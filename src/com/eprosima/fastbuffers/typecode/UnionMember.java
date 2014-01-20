/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.typecode;

import java.util.List;
import java.util.ArrayList;

public class UnionMember extends Member
{
    public UnionMember()
    {
        super();
        m_labels = new ArrayList<String>();
    }
    
    public UnionMember(TypeCode typecode, String name)
    {
        super(typecode, name);
        m_labels = new ArrayList<String>();
    }
    
    public void addLabel(String label)
    {
        m_labels.add(label);
    }
    
    public List<String> getLabels()
    {
        return m_labels;
    }
    
    public boolean isDefault()
    {
        return m_default;
    }
    
    public void setDefault(boolean b)
    {
        m_default = b;
    }
    
    private List<String> m_labels = null;
    
    private boolean m_default = false;
}
