package com.eprosima.ebuffers.typecode;

import org.antlr.stringtemplate.StringTemplate;

public class EnumTypeCode extends MemberedTypeCode
{
    public EnumTypeCode(String scope, String name)
    {
        super(TypeCode.KIND_ENUM, scope, name);
    }
    
    public void addMember(EnumMember member)
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
