package com.eprosima.fastbuffers.context;

import java.util.ArrayList;
import java.util.Map;
import java.util.Iterator;
import java.util.Stack;

import com.eprosima.fastbuffers.FastBuffers;
import com.eprosima.idl.parser.typecode.TypeCode;

public class Context extends com.eprosima.idl.context.Context
{
    public Context(String filename, String file, ArrayList includePaths, FastBuffers.SERIALIZER serializer)
    {
        super(filename, file, includePaths);
        
        m_serializer = serializer;
    }

    public boolean isAnyCdr()
    {
        return true;
    }

    public boolean isCdr()
    {
        if(m_serializer == FastBuffers.SERIALIZER.CDR)
            return true;

        return false;
    }

    public boolean isFastcdr()
    {
        if(m_serializer == FastBuffers.SERIALIZER.FASTCDR)
            return true;

        return false;
    }

    public boolean isFastrpcProduct()
    {
        return false;
    }

    public TypeCode getFirstStructure()
    {
        if(m_firstStructure == null)
        {
            Iterator it = m_types.entrySet().iterator();

            while(it.hasNext())
            {
                Map.Entry e = (Map.Entry)it.next();
                TypeCode aux = (TypeCode)e.getValue();

                if(aux.getKind() == TypeCode.KIND_STRUCT)
                {
                    m_firstStructure = aux;
                    break;
                }
            }
        }
        
        return m_firstStructure;
    }

    // TODO Esta repetido en fastrpc y fastbuffers
    public String getNewRandomName()
    {
        String name = "type_" + ++m_randomGenName;
        m_randomGenNames.push(name);
        return name;
    }

    public String getNewLoopVarName()
    {
        m_loopVarName = 'a';
        return Character.toString(m_loopVarName);
    }

    public String getNextLoopVarName()
    {
        return Character.toString(++m_loopVarName);
    }

    // TODO Para stringtemplate TopicsPlugin de nuestros tipos DDS.
    public String getLastRandomName()
    {
        return m_randomGenNames.pop();
    }

    private FastBuffers.SERIALIZER m_serializer = FastBuffers.SERIALIZER.CDR;
    private TypeCode m_firstStructure = null;

    // TODO Lleva la cuenta de generación de nuevos nombres.
    private int m_randomGenName = 0;
    private Stack<String> m_randomGenNames = null;
    // TODO Lleva la cuenta del nombre de variables para bucles anidados.
    private char m_loopVarName = 'a';
}
