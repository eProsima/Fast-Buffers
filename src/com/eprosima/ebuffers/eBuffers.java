package com.eprosima.ebuffers;

import com.eprosima.ebuffers.exceptions.*;
import com.eprosima.ebuffers.parser.*;

import java.io.*;
import java.util.Vector;

import org.antlr.stringtemplate.StringTemplate;
import org.antlr.stringtemplate.StringTemplateGroup;
import org.antlr.stringtemplate.language.DefaultTemplateLexer;

public class eBuffers
{
    private static String m_version = "0.1.0";
    private Vector<String> m_idlFiles;
    private String m_outputDir = "." + File.separator;
    private String m_exampleOption = null;
    private boolean m_replace = false;
    
    private static VSConfiguration m_vsconfigurations[]={new VSConfiguration("Debug DLL", "Win32", true, true),
        new VSConfiguration("Release DLL", "Win32", false, true),
        new VSConfiguration("Debug", "Win32", true, false),
        new VSConfiguration("Release", "Win32", false, false)};
    
    public eBuffers(String[] args) throws BadArgumentException
    {
        int count = 0;
        m_idlFiles = new Vector<String>();
        
        while(count < args.length)
        {
            if(args[count].equals("-o"))
            {
                if(++count < args.length)
                {
                    m_outputDir = Utils.addFileSeparator(args[count]);
                    
                }
                else
                {
                    throw new BadArgumentException("No directory after -o argument.");
                }
            }
            else if(args[count].equals("-example"))
            {
                if(++count < args.length)
                {
                    m_exampleOption = args[count];

                    if(!m_exampleOption.equals("i86Win32VS2010") &&
                            !m_exampleOption.equals("x64Win64VS2010") &&
                            !m_exampleOption.equals("i86Linux2.6gcc4.4.5") &&
                            !m_exampleOption.equals("x64Linux2.6gcc4.4.5"))
                    {
                        throw new BadArgumentException("Unknown example arch " + m_exampleOption);
                    }
                }
                else
                {
                    throw new BadArgumentException("No platform after -example argument.");
                }
            }
            else if(args[count].equals("-replace"))
            {
                m_replace = true;
            }
            else if(args[count].equals("-version"))
            {
                System.out.println("eBuffers Version " + m_version);
                System.exit(0);
            }
            else
            {
                // Check extension.
                if(args[count].endsWith(".idl"))
                {
                    m_idlFiles.add(args[count]);
                }
                else
                {
                    throw new BadArgumentException("Expected the extension .idl");
                }
            }
            
            ++count;
        }
        
        if(m_idlFiles.isEmpty())
        {
            throw new BadArgumentException("No IDL files.");
        }
    }
    
    public boolean execute()
    {
        boolean returnedValue = true;
        
        for(int count = 0; returnedValue && (count < m_idlFiles.size()); ++count)
        {
            returnedValue &= process(m_idlFiles.get(count));
        }
        
        if(m_exampleOption != null)
        {
            if(genSolution() == false)
                System.out.println("ERROR: While the solution was being generated");
        }
        
        return returnedValue;
    }
    
    private boolean process(String idlFilename)
    {
        boolean returnedValue = false;
        System.out.println("Processing the file " + idlFilename + "...");
        
        try
        {
            InputStream input = new FileInputStream(idlFilename);
            IDLLexer lexer = new IDLLexer(input);
            IDLParser parser = new IDLParser(lexer);
            // Pass the filename without the extension.
            returnedValue = parser.specification(m_outputDir, Utils.getIDLFileNameOnly(idlFilename), m_replace);
        }
        catch(FileNotFoundException ex)
        {
            System.out.println("ERROR<FileNotFoundException>: The file " + idlFilename + "was not found.");
        }
        catch(Exception ex)
        {
            System.out.println("ERROR<Exception>: " + ex.getMessage());
        }
        
        return returnedValue;
    }
    
    private boolean genSolution()
    {
        final String METHOD_NAME = "genSolution";
        boolean returnedValue = true;

        if(m_exampleOption != null)
        {
            if(m_exampleOption.substring(3, 6).equals("Win"))
            {
                System.out.println("Genering VS2010 solution");
                
                if(m_exampleOption.startsWith("i86"))
                {
                    returnedValue = genVS2010(null);
                }
                else if(m_exampleOption.startsWith("x64"))
                {
                    for(int index = 0; index < m_vsconfigurations.length; index++)
                    {
                        m_vsconfigurations[index].setPlatform("x64");
                    }
                    
                    returnedValue = genVS2010("64");
                }
                else
                    returnedValue = false;

            }
            else if(m_exampleOption.substring(3, 8).equals("Linux"))
            {        
                System.out.println("Genering makefile solution");

                if(m_exampleOption.startsWith("i86"))
                {
                    returnedValue = genMakefile("32");
                }
                else if(m_exampleOption.startsWith("x64"))
                {
                    returnedValue = genMakefile("64");
                }
                else
                    returnedValue = false;
            }
        }

        return returnedValue;
    }
    
    private boolean genVS2010(String arch)
    {
        final String METHOD_NAME = "genVS2010";
        boolean returnedValue = false;
        String idlFilename = null, guid = null;
        
        // first load main language template
        StringTemplateGroup vsTemplates = StringTemplateGroup.loadGroup("VS2010", DefaultTemplateLexer.class, null);

        if(vsTemplates != null)
        {
            StringTemplate solution = vsTemplates.getInstanceOf("solution");
            StringTemplate project = null;
            StringTemplate projectFiles = vsTemplates.getInstanceOf("projectFiles");
            
            returnedValue = true;
            for(int count = 0; returnedValue && (count < m_idlFiles.size()); ++count)
            {
                idlFilename = Utils.getIDLFileNameOnly(m_idlFiles.get(count));
                guid = GUIDGenerator.genGUID(idlFilename);
                
                solution.setAttribute("projects.{name, guid, dependsOn, example}", idlFilename, guid, null, m_exampleOption);
                
                project = vsTemplates.getInstanceOf("project");
                project.setAttribute("guid", guid);
                project.setAttribute("name", idlFilename);
                project.setAttribute("example", m_exampleOption);
                project.setAttribute("arch", arch);
                projectFiles.setAttribute("name", idlFilename);
                
                // project configurations   
                for(int index = 0; index < m_vsconfigurations.length; index++){
                    project.setAttribute("configurations", m_vsconfigurations[index]);
                }
                
                if(returnedValue = Utils.writeFile(m_outputDir + idlFilename +"-" + m_exampleOption + ".vcxproj", project, m_replace))
                {
                    returnedValue = Utils.writeFile(m_outputDir + idlFilename +"-" + m_exampleOption + ".vcxproj.filters", projectFiles, m_replace);
                }
            }
            
            // TODO Nombre del la solucion
            if(returnedValue)
            {
                // project configurations   
                for(int index = 0; index < m_vsconfigurations.length; index++){
                    solution.setAttribute("configurations", m_vsconfigurations[index]);
                }
                
                returnedValue = Utils.writeFile(m_outputDir + idlFilename +"-" + m_exampleOption + ".sln", solution, m_replace);
            }
        }
        else
        {
            System.out.println("ERROR<" + METHOD_NAME + ">: Cannot load the template group VS2010");
        }
        
        return returnedValue;
    }
    
    private boolean genMakefile(String arch)
    {
    	boolean returnedValue = false;
    	String idlFilename = null;
    	StringTemplate makecxx = null;
    	
    	StringTemplateGroup makeTemplates = StringTemplateGroup.loadGroup("makefile", DefaultTemplateLexer.class, null);
    	
    	if(makeTemplates != null)
    	{
    		makecxx = makeTemplates.getInstanceOf("makecxx");
    		
    		returnedValue = true;
            for(int count = 0; returnedValue && (count < m_idlFiles.size()); ++count)
            {
            	idlFilename = Utils.getIDLFileNameOnly(m_idlFiles.get(count));
	    			
	    		makecxx.setAttribute("projnames", idlFilename);	
            }
            
            makecxx.setAttribute("example", m_exampleOption);
    		makecxx.setAttribute("arch", arch);	
            
            returnedValue = Utils.writeFile(m_outputDir + "makefile_" + m_exampleOption, makecxx, m_replace);
    	}
    	
    	return returnedValue;
    }
    
    public static void printHelp()
    {
        System.out.println("eBuffers usage:");
        System.out.println("\teBuffers [<options>] <IDL file> [<IDL file> ...]");
        System.out.println("\twhere the options are:");
        System.out.println("\t\t-help: Show help.");
        System.out.println("\t\t-version: shows the current version of RPCDDS.");
        System.out.println("\t\t-o <directory>: Output directory where the generated files will be put.");         
        System.out.println("\t\t-example <platform>: Generate solution for specific platform (example: x64Win64VS2010)\n" +
        "                        Platforms supported:\n" +
        "                         * i86Win32VS2010\n" +
        "                         * x64Win64VS2010\n" +
        "                         * i86Linux2.6gcc4.4.5\n" +
        "                         * x64Linux2.6gcc4.4.5\n");
        System.out.println("\t\t-replace: replace generated files if they exits.");
    }
    
    public static void main(String[] args) throws Exception
    {
        try
        {
            eBuffers main = new eBuffers(args);
            main.execute();
        }
        catch(BadArgumentException ex)
        {
            System.out.println("ERROR<BadArgumentException>: " + ex.getMessage());
            printHelp();
        }
        
        System.exit(-1);
    }
}
