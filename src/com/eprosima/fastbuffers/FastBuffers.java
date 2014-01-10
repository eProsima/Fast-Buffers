/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers;

import com.eprosima.fastbuffers.exceptions.*;
import com.eprosima.fastbuffers.parser.*;

import java.io.*;
import java.util.Vector;
import java.util.ArrayList;

import org.antlr.stringtemplate.StringTemplate;
import org.antlr.stringtemplate.StringTemplateGroup;
import org.antlr.stringtemplate.language.DefaultTemplateLexer;

public class FastBuffers
{
    private Vector<String> m_idlFiles;
    private String m_outputDir = "." + File.separator;
    private String m_exampleOption = null;
    private String m_serType = "CDR";
    private boolean m_replace = false;
    private boolean m_local = false;
    
    private static VSConfiguration m_vsconfigurations[]={new VSConfiguration("Debug DLL", "Win32", true, true),
        new VSConfiguration("Release DLL", "Win32", false, true),
        new VSConfiguration("Debug", "Win32", true, false),
        new VSConfiguration("Release", "Win32", false, false)};
    private static ArrayList<String> m_platforms = null;
    
    public FastBuffers(String[] args) throws BadArgumentException
    {
        int count = 0;
        m_idlFiles = new Vector<String>();
        
        while(count < args.length)
        {
            if(args[count].equals("-d"))
            {
                if(++count < args.length)
                {
                    m_outputDir = Utils.addFileSeparator(args[count]);
                    
                }
                else
                {
                    throw new BadArgumentException("No directory after -d argument.");
                }
            }
            else if(args[count].equals("-example"))
            {
                if(++count < args.length)
                {
                    m_exampleOption = args[count];
                    
                    if(!m_platforms.contains(m_exampleOption))
                    {
                        throw new BadArgumentException("Unknown example arch " + m_exampleOption);
                    }
                }
                else
                {
                    throw new BadArgumentException("No platform after -example argument.");
                }
            }
            else if(args[count].equals("-ser"))
            {
                if(++count < args.length)
                {
                    if(args[count].equals("cdr"))
                    {
                        m_serType = "CDR";
                    }
                    else if(args[count].equals("fastcdr"))
                    {
                        m_serType = "FastCDR";
                    }
                    else
                    {
                        throw new BadArgumentException("No serialization type after -ser argument.");
                    }
                }
                else
                {
                    throw new BadArgumentException("No platform after -ser argument.");
                }
            }
            else if(args[count].equals("-replace"))
            {
                m_replace = true;
            }
            else if(args[count].equals("-version"))
            {
                showVersion();
                System.exit(0);
            }
            else if(args[count].equals("-local"))
            {
                m_local = true;
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
        
        if(returnedValue && (m_exampleOption != null))
        {
            if((returnedValue = genSolution()) == false)
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
            returnedValue = parser.specification(m_outputDir, Utils.getIDLFileNameOnly(idlFilename), m_serType,
                    m_replace, (m_exampleOption != null ? true : false));
        }
        catch(FileNotFoundException ex)
        {
            System.out.println("ERROR<FileNotFoundException>: The file " + idlFilename + "was not found.");
        }
        catch(ParseException ex)
        {
        	System.out.println("ERROR<ParseException>: " + ex.getMessage());
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
        String idlFilename = null, guid = null, guidExample = null;
        
        // first load main language template
        StringTemplateGroup vsTemplates = StringTemplateGroup.loadGroup("VS2010", DefaultTemplateLexer.class, null);

        if(vsTemplates != null)
        {
            StringTemplate solution = vsTemplates.getInstanceOf("solution");
            StringTemplate project = vsTemplates.getInstanceOf("project");;
            StringTemplate projectFiles = vsTemplates.getInstanceOf("projectFiles");
            StringTemplate projectExample = vsTemplates.getInstanceOf("projectExample");
            StringTemplate projectExampleFiles = vsTemplates.getInstanceOf("projectExampleFiles");
            
            returnedValue = true;
            for(int count = 0; returnedValue && (count < m_idlFiles.size()); ++count)
            {
                idlFilename = Utils.getIDLFileNameOnly(m_idlFiles.get(count));
                guid = GUIDGenerator.genGUID(idlFilename);
                guidExample = GUIDGenerator.genGUID("Example" + idlFilename);
                
                solution.setAttribute("projects.{name, guid, guidExample, dependsOn, example}", idlFilename, guid, guidExample, null, m_exampleOption);
                
                project.setAttribute("guid", guid);
                project.setAttribute("name", idlFilename);
                project.setAttribute("example", m_exampleOption);
                project.setAttribute("arch", arch);
                project.setAttribute("local", m_local);
                projectFiles.setAttribute("name", idlFilename);
                
                projectExample.setAttribute("guid", guidExample);
                projectExample.setAttribute("guidParent", guid);
                projectExample.setAttribute("name", idlFilename);
                projectExample.setAttribute("example", m_exampleOption);
                projectExample.setAttribute("arch", arch);
                projectExample.setAttribute("local", m_local);
                projectExampleFiles.setAttribute("name", idlFilename);
                
                // project configurations   
                for(int index = 0; index < m_vsconfigurations.length; index++){
                    project.setAttribute("configurations", m_vsconfigurations[index]);
                    projectExample.setAttribute("configurations", m_vsconfigurations[index]);
                }
                
                if(returnedValue = Utils.writeFile(m_outputDir + idlFilename +"-" + m_exampleOption + ".vcxproj", project, m_replace))
                {
                    if(returnedValue = Utils.writeFile(m_outputDir + idlFilename +"-" + m_exampleOption + ".vcxproj.filters", projectFiles, m_replace))
                    {
                    	if(returnedValue = Utils.writeFile(m_outputDir + idlFilename +"Example-" + m_exampleOption + ".vcxproj", projectExample, m_replace))
                        {
                            returnedValue = Utils.writeFile(m_outputDir + idlFilename +"Example-" + m_exampleOption + ".vcxproj.filters", projectExampleFiles, m_replace);
                        }
                    }
                }
                
                project.reset();
                projectFiles.reset();
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
    		makecxx.setAttribute("local", m_local);   
            
            returnedValue = Utils.writeFile(m_outputDir + "makefile_" + m_exampleOption, makecxx, m_replace);
    	}
    	
    	return returnedValue;
    }
    
    public static void printHelp()
    {
        System.out.println("FastBuffers usage:");
        System.out.println("\tfastbuffers [<options>] <IDL file> [<IDL file> ...]");
        System.out.println("\twhere the options are:");
        System.out.println("\t\t-help: Show help.");
        System.out.println("\t\t-version: shows the current version of Fast Buffers.");
        System.out.println("\t\t-d <directory>: Output directory where the generated files will be put.");         
        System.out.println("\t\t-example <platform>: Generate solution for specific platform (example: x64Win64VS2010)\n" +
        "                        Platforms supported:");
        for(int count = 0; count < m_platforms.size(); ++count)
        	System.out.println("                         * " + m_platforms.get(count));
        System.out.println("");
        System.out.println("\t\t-ser <serialization>: Serialization type (default: cdr)\n" +
                "                        Serialization type supported:\n" +
                "                         * cdr\n" +
                "                         * fastcdr\n");
        System.out.println("\t\t-replace: replace generated files if they exits.");
    }
    
    public void showVersion()
    {
    	try
    	{
	    	InputStream input = this.getClass().getResourceAsStream("/version.cpp");
	    	byte[] b = new byte[input.available()];
	    	input.read(b);
	    	String text = new String(b);
	    	int beginindex = text.indexOf("\"");
	    	int endindex = text.indexOf("\"", beginindex + 1);
	    	String version = text.substring(beginindex + 1, endindex);
	    	System.out.println("FastBuffers Version " + version);
    	}
    	catch(Exception ex)
    	{
    		System.out.println("ERROR: Getting version. " + ex.getMessage());
    	}
    }
    
    public static boolean loadPlatforms()
    {
    	boolean returnedValue = false;
    	
    	FastBuffers.m_platforms = new ArrayList<String>();
    	
    	try
    	{
    		InputStream input = FastBuffers.class.getResourceAsStream("/platforms");
    		InputStreamReader ir = new InputStreamReader(input);
			BufferedReader reader = new BufferedReader(ir);
			String line = null;
			while((line = reader.readLine()) != null)
			{
				FastBuffers.m_platforms.add(line);
			}
			
			returnedValue = true;
    	}
    	catch(Exception ex)
    	{
    		System.out.println("ERROR: Getting platforms. " + ex.getMessage());
    	}
    	
    	return returnedValue;
    }
    
    public static void main(String[] args) throws Exception
    {
    	if(loadPlatforms())
    	{
	        try
	        {
	            FastBuffers main = new FastBuffers(args);
	            if(main.execute())
	            	System.exit(0);
	        }
	        catch(BadArgumentException ex)
	        {
	            System.out.println("ERROR<BadArgumentException>: " + ex.getMessage());
	            printHelp();
	        }
    	}
        
        System.exit(-1);
    }
}
