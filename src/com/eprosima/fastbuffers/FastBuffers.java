/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers;

import com.eprosima.fastbuffers.exceptions.*;
import com.eprosima.solution.*;
import com.eprosima.idl.util.Util;
import com.eprosima.fastbuffers.context.Context;
import com.eprosima.idl.parser.grammar.IDLLexer;
import com.eprosima.idl.parser.grammar.IDLParser;
import com.eprosima.idl.parser.exception.ParseException;
import com.eprosima.idl.generator.manager.TemplateGroup;
import com.eprosima.idl.generator.manager.TemplateManager;
import com.eprosima.idl.parser.typecode.TypeCode;

import java.io.*;
import java.util.Vector;
import java.util.ArrayList;

import org.antlr.stringtemplate.StringTemplate;
import org.antlr.stringtemplate.StringTemplateErrorListener;
import org.antlr.stringtemplate.StringTemplateGroup;
import org.antlr.stringtemplate.StringTemplateGroupLoader;
import org.antlr.stringtemplate.CommonGroupLoader;
import org.antlr.stringtemplate.language.DefaultTemplateLexer;

public class FastBuffers
{
    class TemplateErrorListener implements StringTemplateErrorListener
    {  
        public void error(String arg0, Throwable arg1)
        {
            System.out.println(arg0);
            arg1.printStackTrace();
        }
    
        public void warning(String arg0)
        {
            System.out.println(arg0);   
        }   
    }

    // Use to know the protocol
    public enum SERIALIZER
    {
        CDR,
        FASTCDR
    };

    private Vector<String> m_idlFiles;
    private final String m_defaultOutputDir = "." + File.separator;
    private String m_outputDir = m_defaultOutputDir;
    private String m_tempDir = null;
    private String m_exampleOption = null;
    private SERIALIZER m_serializer = SERIALIZER.CDR;
    private boolean m_replace = false;
    private boolean m_local = false;
    private boolean m_ppDisable = false;
    private String m_ppPath = null;
    private ArrayList m_includePaths = new ArrayList();
    private String m_os = null;
    
    private static VSConfiguration m_vsconfigurations[]={new VSConfiguration("Debug DLL", "Win32", true, true),
        new VSConfiguration("Release DLL", "Win32", false, true),
        new VSConfiguration("Debug", "Win32", true, false),
        new VSConfiguration("Release", "Win32", false, false)};
    private static ArrayList<String> m_platforms = null;
    
    public FastBuffers(String[] args) throws BadArgumentException
    {
        int count = 0;
        m_idlFiles = new Vector<String>();

        // Detect OS system
        // Detect OS
        m_os = System.getProperty("os.name");
        
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
                        m_serializer = SERIALIZER.CDR;
                    }
                    else if(args[count].equals("fastcdr"))
                    {
                        m_serializer = SERIALIZER.FASTCDR;
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
            else if(args[count].equals("-ppPath"))
            {
                if(++count < args.length)
                    m_ppPath = args[count];
                else
                    throw new BadArgumentException("No URL after -ppPath argument");
            }
            else if(args[count].equalsIgnoreCase("-ppDisable"))
            {
                m_ppDisable = true;
            }
            // Get include directories
            else if(args[count].equals("-I"))
            {
                if(++count < args.length)
                {
                    m_includePaths.add(new String("-I" + args[count]));
                }
                else
                    throw new BadArgumentException("No URL after -I argument");
            }
            else if(args[count].startsWith("-I"))
            {
                m_includePaths.add(args[count]);
            }
            else if(args[count].equals("-t"))
            {
                if(++count < args.length)
                {
                    m_tempDir = args[count];
                }
                else
                    throw new BadArgumentException("No URL after -t argument");
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
    	// Check the output directory.
    	if(!m_outputDir.equals(m_defaultOutputDir))
    	{
    		File dir = new File(m_outputDir);
    		
    		if(!dir.exists())
    		{
    			System.out.println("ERROR: The output directory doesn't exist");
    			return false;
    		}
    	}

        // Set the temporary folder.
        if(m_tempDir == null)
        {
        	if(m_os.contains("Windows"))
        	{
        		String tempPath = System.getenv("TEMP");
        		
        		if(tempPath == null)
        			tempPath = System.getenv("TMP");
        		
        		m_tempDir = tempPath;
        	}
        	else if(m_os.contains("Linux"))
        	{
        		m_tempDir = "/tmp/";
        	}
        }
        if(m_tempDir.charAt(m_tempDir.length() - 1) != File.separatorChar)
		{
			m_tempDir += File.separator;
		}

        // Load main string templates.
        // Load string templates
        System.out.println("Loading Templates...");     
        StringTemplateGroupLoader loader = new CommonGroupLoader("com/eprosima/fastbuffers/templates", new TemplateErrorListener());
        StringTemplateGroup.registerGroupLoader(loader);
        TypeCode.cpptypesgr = StringTemplateGroup.loadGroup("Types", DefaultTemplateLexer.class, null);

        boolean returnedValue = true;
        Solution solution = new Solution();
        
        for(int count = 0; returnedValue && (count < m_idlFiles.size()); ++count)
        {
            Project project = process(m_idlFiles.get(count));

            if(project != null)
                solution.addProject(project);
            else
                returnedValue = false;
        }
        
        if(returnedValue && (m_exampleOption != null))
        {
            if((returnedValue = genSolution(solution)) == false)
                System.out.println("ERROR: While the solution was being generated");
        }
        
        return returnedValue;
    }
    
    private Project process(String idlFilename)
    {
        boolean returnedValue = false;
        String idlParseFileName = idlFilename;
        Project project = null;
        System.out.println("Processing the file " + idlFilename + "...");

        String onlyFileName = Util.getIDLFileNameOnly(idlFilename);

        if(!m_ppDisable)
        {
            idlParseFileName = callPreprocessor(idlFilename);
        }

        if(idlParseFileName != null)
        {
            // Create initial context.
            Context ctx = new Context(onlyFileName, idlFilename, m_includePaths, m_serializer);

            // Create template manager
            TemplateManager tmanager = new TemplateManager();
            // Load template to generate source for common types.
            tmanager.addGroup("TypesHeader");
            tmanager.addGroup("TypesSource");
            tmanager.addGroup("ExampleSource");

	        // Create main template for all templates.
	        TemplateGroup maintemplates = tmanager.createTemplateGroup("main");
	        maintemplates.setAttribute("ctx", ctx);	        

            try
            {
                InputStream input = new FileInputStream(idlFilename);
                IDLLexer lexer = new IDLLexer(input);
                IDLParser parser = new IDLParser(lexer);
                // Pass the filename without the extension.
                returnedValue = parser.specification(ctx, tmanager, maintemplates);
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

            if(returnedValue)
            {
	        	project = new Project(onlyFileName, idlFilename, ctx.getDependencies());

                System.out.println("Generating Code...");

                if(returnedValue = Utils.writeFile(m_outputDir + onlyFileName + ".h", maintemplates.getTemplate("TypesHeader"), m_replace))
                {
                    if(returnedValue = Utils.writeFile(m_outputDir + onlyFileName + ".cpp", maintemplates.getTemplate("TypesSource"), m_replace))
                    {
                        project.addCommonIncludeFile(onlyFileName + ".h");
                        project.addCommonSrcFile(onlyFileName + ".cpp");

                        if(m_exampleOption != null)
                            returnedValue = Utils.writeFile(m_outputDir + onlyFileName + "Example.cpp", maintemplates.getTemplate("ExampleSource"), m_replace);
                    }
                }
            }
        }
        
        return project;
    }

    /*!
     * @return The file used to store the preprocessed idl file. In error case null pointer is returned.
     */
    String callPreprocessor(String idlFilename)
    {
    	// Set line command.
        ArrayList lineCommand = new ArrayList();
        String[] lineCommandArray = null;
        String outputfile = Util.getIDLFileOnly(idlFilename) + ".cc";
        int exitVal = -1;
        OutputStream of = null;
        
        // Use temp directory.
        if(m_tempDir != null)
        	outputfile = m_tempDir + outputfile;
        
        if(m_os.contains("Windows"))
        {
        	try
            {
            	of = new FileOutputStream(outputfile);
            }
            catch(FileNotFoundException ex)
            {
            	System.out.println("ERROR<callPreprocessor>: Cannot open file " + outputfile);
            	return null;
            }
        }
        
        // Set the preprocessor path
        String ppPath = m_ppPath;
        
        if(ppPath == null)
        {
        	if(m_os.contains("Windows"))
        	{
        		ppPath = "cl.exe";
        	}
        	else if(m_os.contains("Linux"))
        	{
        		ppPath = "cpp";
        	}
        }
        
        // Add command
        lineCommand.add(ppPath);
        
        // Add the include paths given as parameters.
        for(int i = 0; i < m_includePaths.size(); ++i)
        {
        	if(m_os.contains("Windows"))
        		lineCommand.add(((String)m_includePaths.get(i)).replaceFirst("^-I", "/I"));
        	else if(m_os.contains("Linux"))
        		lineCommand.add(m_includePaths.get(i));
        }
        
        if(m_os.contains("Windows"))
        {
        	lineCommand.add("/E");
        	lineCommand.add("/C");
        }
        
        // Add input file.
        lineCommand.add(idlFilename);
        
        if(m_os.contains("Linux"))
        {
        	// Add output file.
        	lineCommand.add(outputfile);
        }
        
        lineCommandArray = new String[lineCommand.size()];
        lineCommandArray = (String[])lineCommand.toArray(lineCommandArray);
        
        try
        {
	        Process preprocessor = Runtime.getRuntime().exec(lineCommandArray);
	        ProcessOutput errorOutput = new ProcessOutput(preprocessor.getErrorStream(), "ERROR", false, null);
	        ProcessOutput normalOutput = new ProcessOutput(preprocessor.getInputStream(), "OUTPUT", false, of);
	        errorOutput.start();
	        normalOutput.start();
	        exitVal = preprocessor.waitFor();
	        errorOutput.join();
	        normalOutput.join();
        }
        catch(Exception ex)
        {
        	System.out.println("Cannot execute the preprocessor. Reason: " + ex.getMessage());
        	return null;
        }
        
        if(of != null)
        {
        	try
        	{
        		of.close();
        	}
        	catch(IOException ex)
        	{
        		System.out.println("ERROR<callPreprocessor>: Cannot close file " + outputfile);
        	}
        }

        if(exitVal != 0)
        {
        	System.out.println("Preprocessor return an error " + exitVal);
        	return null;
        }
        
        return outputfile;
    }
    
    private boolean genSolution(Solution solution)
    {
        final String METHOD_NAME = "genSolution";
        boolean returnedValue = true;

        if(m_exampleOption != null)
        {
            System.out.println("Generating solution for arch " + m_exampleOption  + "...");

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
                    returnedValue = genMakefile(solution, "32");
                }
                else if(m_exampleOption.startsWith("x64"))
                {
                    returnedValue = genMakefile(solution, "64");
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
    
    private boolean genMakefile(Solution solution, String arch)
    {
    	boolean returnedValue = false;
    	StringTemplate makecxx = null;
    	
    	StringTemplateGroup makeTemplates = StringTemplateGroup.loadGroup("makefile", DefaultTemplateLexer.class, null);
    	
    	if(makeTemplates != null)
    	{
    		makecxx = makeTemplates.getInstanceOf("makecxx");
    		
            makecxx.setAttribute("solution", solution);
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

class ProcessOutput extends Thread
{
    InputStream is = null;
    OutputStream of = null;
    String type;
    boolean m_check_failures;
    boolean m_found_error = false;
    final String clLine = "#line";

    ProcessOutput(InputStream is, String type, boolean check_failures, OutputStream of)
    {
        this.is = is;
        this.type = type;
        m_check_failures = check_failures;
        this.of = of;
    }

    public void run()
    {
        try
        {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader br = new BufferedReader(isr);
            String line=null;
            while ( (line = br.readLine()) != null)
            {
            	if(of == null)
            		System.out.println(line);
            	else
            	{
            		// Sustituir los \\ que pone cl.exe por \
            		if(line.startsWith(clLine))
            		{
            			line = "#" + line.substring(clLine.length());
	            		int count = 0;
	            		while((count = line.indexOf("\\\\")) != -1)
	            		{
	            			line = line.substring(0, count) + "\\" + line.substring(count + 2);
	            		}
            		}

            		of.write(line.getBytes());
            		of.write('\n');
            	}
                
                if(m_check_failures)
                {
                	if(line.startsWith("Done (failures)"))
                	{
                		m_found_error = true;
                	}
                }
            }
        }
        catch (IOException ioe)
        {
            ioe.printStackTrace();  
        }
    }
    
    boolean getFoundError()
    {
    	return m_found_error;
    }
}
