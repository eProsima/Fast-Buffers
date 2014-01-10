/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastBuffers is licensed to you under the terms described in the
 * FAST_BUFFERS_LICENSE file included in this distribution.
 *
 *************************************************************************/

package com.eprosima.fastbuffers.templates;

import com.eprosima.fastbuffers.templates.TemplateGroup;

import java.util.Iterator;
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;

import org.antlr.stringtemplate.*;
import org.antlr.stringtemplate.language.DefaultTemplateLexer;

public class TemplateManager
{
    class TemplateErrorListener implements StringTemplateErrorListener
    {  
        public void error(String arg0, Throwable arg1)
        {
            System.out.println(arg0);
            arg1.printStackTrace();
        }
    
        public void warning(String arg0)
        {
            System.out.println(arg0);   
        }   
    }
    
    private Map<String, StringTemplateGroup> m_groups;
    private StringTemplateGroup commongr = null;
    
    public TemplateManager(String templateLocation)
    {
        m_groups = new HashMap<String, StringTemplateGroup>();
        
        System.out.println("Loading Templates...");     
        StringTemplateGroupLoader loader = new CommonGroupLoader(templateLocation, new TemplateErrorListener());
        StringTemplateGroup.registerGroupLoader(loader);
        
        // Load common stringtemplate rules.
        commongr = StringTemplateGroup.loadGroup("Common", DefaultTemplateLexer.class, null);
    }
    
    public void addGroup(String groupname)
    {
        StringTemplateGroup group = StringTemplateGroup.loadGroup(groupname, DefaultTemplateLexer.class, commongr);
        m_groups.put(groupname, group);
    }
    
    public TemplateGroup createTemplateGroup(String templatename)
    {
        TemplateGroup tg = new TemplateGroup();
        Set<Entry<String, StringTemplateGroup>> set = m_groups.entrySet();
        Iterator<Entry<String, StringTemplateGroup>> it = set.iterator();
        
        while(it.hasNext())
        {
            Map.Entry<String, StringTemplateGroup> m = (Map.Entry<String, StringTemplateGroup>)it.next();
            
            // Obtain instance
            StringTemplate template = m.getValue().getInstanceOf(templatename);
            tg.addTemplate(m.getKey(), template);
        }
        
        return tg;
    }
    
    public StringTemplate createStringTemplate(String templatename)
    {     
        return commongr.getInstanceOf(templatename);
    }
}
