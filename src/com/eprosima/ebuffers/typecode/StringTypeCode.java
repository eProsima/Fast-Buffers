package com.eprosima.ebuffers.typecode;

public class StringTypeCode extends TypeCode
{
    public StringTypeCode(int kind, String maxsize)
    {
        super(kind);
        m_maxsize = maxsize;
    }
    @Override
    public String getTypename()
    {
        return getStringTemplate().toString();
    }
    
    public String getMaxsize()
    {
        return m_maxsize;
    }
    
    private String m_maxsize = null;
}
