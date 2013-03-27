package com.eprosima.ebuffers.typecode;

import org.antlr.stringtemplate.StringTemplate;

import java.util.List;
import java.util.ArrayList;

public class UnionTypeCode extends MemberedTypeCode
{
    public UnionTypeCode(String scope, String name, TypeCode discriminatorTypeCode)
    {
        super(TypeCode.KIND_UNION, scope, name);
        m_discriminatorTypeCode = discriminatorTypeCode;
    }
    
    public int addMember(UnionMember member)
    {
        return addMember((Member)member);
    }
    
    @Override
    public String getTypename()
    {
        StringTemplate st = getStringTemplate();
        st.setAttribute("name", getScopedname());
        return st.toString();
    }
    
    public void setDefaultindex(int index)
    {
        if(m_defaultindex != -1)
            ((UnionMember)getMembers().get(m_defaultindex)).setDefault(false);
        
        m_defaultindex = index;
        ((UnionMember)getMembers().get(m_defaultindex)).setDefault(true);
    }
    
    public void setDefaultvalue(String value)
    {
        m_defaultValue = value;
    }
    
    // Used in stringtemplates
    public String getDefaultvalue()
    {
        return m_defaultValue;
    }
    
    // Used in stringtemplates
    public TypeCode getDiscriminator()
    {
        return m_discriminatorTypeCode;
    }
    
    // Used in stringtemplates
    public List<String> getTotallabels()
    {
        List<String> returnList = new ArrayList<String>();
        List<Member> mlist = getMembers();
        List<String> labels = null;
        
        for(int count = 0; count < mlist.size(); ++count)
        {
            if(count != m_defaultindex)
            {
                labels = ((UnionMember)mlist.get(count)).getLabels();
                for(int i = 0; i < labels.size(); ++i)
                    returnList.add(labels.get(i));
            }
        }
        
        return returnList;
    }
    
    private TypeCode m_discriminatorTypeCode = null;
    
    private int m_defaultindex = -1;
    
    private String m_defaultValue = null;
}
