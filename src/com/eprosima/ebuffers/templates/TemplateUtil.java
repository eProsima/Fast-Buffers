package com.eprosima.ebuffers.templates;

import java.util.List;

public class TemplateUtil
{
    public static String stripType(String type)
    {
        if(type.startsWith("std::array"))
            return "std::array";
        else if(type.startsWith("std::vector"))
            return "std::vector";
        else
            return type;
    }
    
    public static String getDefaultLabel(String dist_type, List<String> total_labels)
    {
        String returnedValue = null;
        
        return returnedValue;
    }
}
