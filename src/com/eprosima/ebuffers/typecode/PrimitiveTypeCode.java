package com.eprosima.ebuffers.typecode;

import com.eprosima.ebuffers.templates.TemplateManager;

public class PrimitiveTypeCode extends TypeCode
{
    public PrimitiveTypeCode(int kind)
    {
        super(kind);
    }

    @Override
    public String getTypename()
    {
        return getStringTemplate().toString();
    }
    
    public boolean isPrimitive()
    {
        return true;
    }
}
