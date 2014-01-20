/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.typecode;

public abstract class Member
{
    public Member()
    {
    }
    
    public Member(TypeCode typecode, String name)
    {
        m_typecode = typecode;
        m_name = name;
    }
    
    public String getName()
    {
        return m_name;
    }
    
    public TypeCode getTypecode()
    {
        return m_typecode;
    }
    
    public void setName(String name)
    {
        m_name = name;
    }
    
    public void setTypecode(TypeCode typecode)
    {
         m_typecode = typecode;
    }
    
    private String m_name = null;
    
    private TypeCode m_typecode = null;
}
