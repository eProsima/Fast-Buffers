/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.typecode;

import org.antlr.stringtemplate.StringTemplate;

import com.eprosima.fastbuffers.util.Pair;

public class SequenceTypeCode extends ContainerTypeCode
{
    public SequenceTypeCode(String maxsize)
    {
        super(TypeCode.KIND_SEQUENCE);
        m_maxsize = maxsize;
    }
    
    @Override
    public String getTypename()
    {
        StringTemplate st = getStringTemplate();
        st.setAttribute("type", getContentTypeCode().getTypename());
        return st.toString();
    }

    public String getMaxsize()
    {
        return m_maxsize;
    }
    
    public Pair<Integer, Integer> getMaxSerializedSize(int currentSize, int lastDataAligned)
    {
        int lcontainTypeSize = getContentTypeCode().getSize();
        int lcontainTypeAlign = 0;
        int lcurrentSize = currentSize;
        
        // Length
        if(4 <= lastDataAligned)
        {
            lcurrentSize += 4;
        }
        else
        {
            int align = (4 - (lcurrentSize % 4)) & (4 - 1);
            lcurrentSize += 4 + align;
        }
        
        // Element contained type.
        if(lcontainTypeSize > 4)
        {
            lcontainTypeAlign = (lcontainTypeSize - (lcurrentSize % lcontainTypeSize)) & (lcontainTypeSize - 1);
        }
        
        if(m_maxsize == null)
        {
            return new Pair<Integer, Integer>(lcurrentSize + lcontainTypeAlign + (255 * lcontainTypeSize), lcontainTypeSize);
        }
        else
        {
            return new Pair<Integer, Integer>(lcurrentSize + lcontainTypeAlign + (Integer.parseInt(m_maxsize) *  lcontainTypeSize), lcontainTypeSize);
        }
    }
    
    public int getMaxSerializedSizeWithoutAlignment(int currentSize)
    {
        int lcontainTypeSize = getContentTypeCode().getSize();
        
        if(m_maxsize == null)
        {
            return currentSize + 4 + (255 * lcontainTypeSize);
        }
        else
        {
            return currentSize + 4 + (Integer.parseInt(m_maxsize) * lcontainTypeSize);
        }
    }
    
    private String m_maxsize = null;
}
