package com.eprosima.ebuffers.typecode;

import org.antlr.stringtemplate.StringTemplate;

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
    
    private String m_maxsize = null;
}
