package com.eprosima.ebuffers;

import com.eprosima.ebuffers.exceptions.*;
import com.eprosima.ebuffers.parser.*;

import java.io.*;
import java.util.Vector;

public class eBuffers
{
    private Vector<String> m_idlFiles;
    private String m_outputDir = ".";
    
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
                    m_outputDir = args[count];
                }
                else
                {
                    throw new BadArgumentException("No directory after -o argument.");
                }
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
            returnedValue = parser.specification(idlFilename.substring(0, idlFilename.length() - 4));
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
    
    public static void printHelp()
    {
        System.out.println("eBuffers usage:");
        System.out.println("\teBuffers [-o <dir>] <IDL file> [<IDL file> ...]");
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
