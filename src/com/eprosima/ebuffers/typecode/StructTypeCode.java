package com.eprosima.ebuffers.typecode;

import java.util.ArrayList;

import org.antlr.stringtemplate.StringTemplate;

public class StructTypeCode extends MemberedTypeCode
{
    public StructTypeCode(String scope, String name)
    {
        super(TypeCode.KIND_STRUCT, scope, name);
    }
    
    public void addMember(StructMember member)
    {
        addMember((Member)member);
    }
    
    @Override
    public String getTypename()
    {
        StringTemplate st = getStringTemplate();
        st.setAttribute("name", getScopedname());
        return st.toString();
    }

}
