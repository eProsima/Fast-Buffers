package com.eprosima.ebuffers.typecode;

import java.util.List;
import java.util.ArrayList;

import org.antlr.stringtemplate.StringTemplate;

public class ArrayTypeCode extends ContainerTypeCode
{
    public ArrayTypeCode()
    {
        super(TypeCode.KIND_ARRAY);
        
        m_dimensions = new ArrayList<String>();
    }
    
    @Override
    public String getTypename()
    {
        StringTemplate first = null, second = null, fin = null;
        String prevf = null, prevs = null;
        
        for(int count = 0; count < m_dimensions.size(); ++count)
        {     
            first = m_typesgr.getInstanceOf("type_" + Integer.toHexString(TypeCode.KIND_ARRAY) + "_first");
            second = m_typesgr.getInstanceOf("type_" + Integer.toHexString(TypeCode.KIND_ARRAY) + "_second");
            second.setAttribute("size", m_dimensions.get(count));
            
            if(prevf != null)
            {
                first.setAttribute("prev", prevf);
            }
            if(prevs != null)
            {
                second.setAttribute("prev", prevs);
            }
            
            prevf = first.toString();
            prevs = second.toString();
        }
        
        fin = getStringTemplate();
        fin.setAttribute("firs", prevf);
        fin.setAttribute("secon", prevs);
        fin.setAttribute("type", getContentTypeCode().getTypename());
        
        return fin.toString();
    }
    
    public void addDimension(String dimension)
    {
        m_dimensions.add(dimension);
    }
    
    private List<String> m_dimensions;
}
