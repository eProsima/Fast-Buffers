header {
    package com.eprosima.ebuffers.parser;
    
    import com.eprosima.ebuffers.templates.TemplateManager;
    import com.eprosima.ebuffers.templates.TemplateGroup;
     import com.eprosima.ebuffers.templates.TemplateUtil;
    import com.eprosima.ebuffers.util.Pair;
    
    import org.antlr.stringtemplate.StringTemplate;
   
    
    import java.io.*;
    import java.util.Vector;
    import java.util.List;
    import java.util.ArrayList;
 }

class IDLParser extends Parser;
options {
	exportVocab=IDL;
	k=4;
}

{   
    class Context
    {
        public Context(String filename)
        {
            m_filename = filename;
        }
        
        public void setFilename(String filename)
        {
            m_filename = filename;
        }
        
        public String getFilename()
        {
            return m_filename;
        }
        
        public void setScope(String scope)
        {
            m_scope = scope;
        }
        
        public String getScope()
        {
            return m_scope;
        }
        
        public void setSersym(String sersym)
        {
            m_sersym = sersym;
        }
        
        public String getSersym()
        {
            return m_sersym;
        }
        
        public void setTypelimitation(String lt)
        {
            m_typelimitation = lt;
        }
        
        public String getTypelimitation()
        {
            return m_typelimitation;
        }
        
        private String m_filename = "";
        private String m_scope = "";
        private String m_sersym = ">>";
        private String m_typelimitation = null;
    }; 
    
    private TemplateManager tmanager = null;
    private Context ctx = null;
    
    private boolean writeFile(String file, StringTemplate template)
    {
        boolean returnedValue = false;
        
        try
        {
            File handle = new File(file);
            
            if(!handle.exists() /*|| replace*/)
            {
                FileWriter fw = new FileWriter(file);
                String data = template.toString();
                fw.write(data, 0, data.length());
                fw.close();
            }
            else
            {
                System.out.println("INFO: " + file + " exists. Skipping.");
            }

            returnedValue = true;
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }   

        return returnedValue;
    }
}

specification [String idlFilename] returns [boolean returnedValue = false]
{
    // Create initial context.
    ctx = new Context(idlFilename);
    
    // Create template manager
    tmanager = new TemplateManager("com/eprosima/ebuffers/templates");
    // Load types header template.
    tmanager.addGroup("TypesHeader");
    // Load types source template.
    tmanager.addGroup("TypesSource");
    // Load CDR header template.
    tmanager.addGroup("CDRHeader");
    // Load CDR header template.
    tmanager.addGroup("CDRSource");
    TemplateGroup maintemplates = tmanager.createTemplateGroup("main");
    maintemplates.setAttribute("ctx", ctx);
    
    TemplateGroup tg = null;
}
	:   (import_dcl)* (tg=definition{maintemplates.setAttribute("blocks", tg);})+
{
    if(writeFile(idlFilename + ".h", maintemplates.getTemplate("TypesHeader")))
    {
        if(writeFile(idlFilename + ".cpp", maintemplates.getTemplate("TypesSource")))
        {
            if(writeFile(idlFilename + "CDR.h", maintemplates.getTemplate("CDRHeader")))
            {
                if(writeFile(idlFilename + "CDR.cpp", maintemplates.getTemplate("CDRSource")))
                {
                    returnedValue = true;
                }
            }
        }
    }
}
	;


definition returns [TemplateGroup tg = null]
	:   (   tg=type_dcl SEMI!
	    |   const_dcl SEMI!
	    |   except_dcl SEMI!
	    |   (("abstract" | "local")? "interface") => interf SEMI!
	    |   tg=module SEMI!
	    |   (("abstract" | "custom")? "valuetype") => value SEMI!
	    |   type_id_dcl SEMI!
	    |   type_prefix_dcl SEMI!
	    |   (("abstract" | "custom")? "eventtype") => event SEMI!
	    |   component SEMI!
	    |   home_dcl SEMI!
	    )
	;

module returns [TemplateGroup moduleTemplates = tmanager.createTemplateGroup("module")]
{
    TemplateGroup tg = null;
    String name = null, old_scope = ctx.getScope();
}
	:    "module"^
	     name=identifier
	     {
	       moduleTemplates.setAttribute("name", name);
	       ctx.setScope(old_scope + name + "::");
	     }	    
	     LCURLY! tg=d:definition_list{moduleTemplates.setAttribute("definition_list", tg);} RCURLY!
	     {
	       ctx.setScope(old_scope);
	     }
	;

definition_list returns [TemplateGroup dlTemplates = tmanager.createTemplateGroup("definition_list")]
{
    TemplateGroup tg = null;
}
	:   (tg=definition{dlTemplates.setAttribute("definitions", tg);})+
	;

interf
    : ( interface_dcl
      | forward_dcl
      )
    ;
 
// Grammar changed to differentiate between 
// forward declared interfaces and empty interfaces
interface_dcl
	:   (( "abstract" | "local" )?
 	    "interface"^
 	    identifier
	    ( interface_inheritance_spec )?	   
	    LCURLY interface_body RCURLY) 
	;
	
forward_dcl
 	:    ( "abstract" | "local" )?
 	    "interface"^
 	    identifier
 	;


interface_body
	:   ( export )*
	;

export
	:   (   type_dcl SEMI!
	    |   const_dcl SEMI!
	    |   except_dcl SEMI!
	    |   attr_dcl SEMI!
	    |   op_dcl SEMI!
	    |   type_id_dcl SEMI!
	    |   type_prefix_dcl SEMI!
	    )
	;


interface_inheritance_spec
	:   COLON^ scoped_name_list
	;

interface_name
	:   scoped_name
	;

scoped_name_list
	:    scoped_name (COMMA! scoped_name)*
	;


scoped_name returns [String literal = ""]
{
    String aux = null;
}
	:  ({literal += LT(1).getText();} SCOPEOP^ )?
	   {literal += LT(1).getText();} IDENT^ /* identifier */
	   ({literal += LT(1).getText();} SCOPEOP! aux=identifier{literal += aux;})*
	;

value
	:   ( value_dcl
	    | value_abs_dcl
	    | value_box_dcl
	    | value_custom_dcl
	    | value_forward_dcl
	    )
	;

value_forward_dcl
	:   "valuetype"^
	    identifier
	;

value_box_dcl
	:   "valuetype"^
	    identifier
	    type_spec
	;

value_abs_dcl
	:   "abstract"
	    "valuetype"^
	    identifier
	    ( value_abs_full_dcl
	    | // value_abs_forward_dcl
	    )
	;

value_abs_full_dcl
	:   value_inheritance_spec
	    LCURLY! ( export )* RCURLY!
	;

// value_abs_forward_dcl
// 	:
// 	;

value_dcl
	:   value_header
	    LCURLY! ( value_element )* RCURLY!
	;

value_custom_dcl
	:   "custom"^
	    value_dcl
	;

value_header
	:   "valuetype"^
	    identifier
	    value_inheritance_spec
	;

value_inheritance_spec
/*
	:   ( COLON ( "truncatable" )?
	      value_name ( COMMA! value_name )*
	    )?
	    ( "supports" interface_name ( COMMA! interface_name )* )?
	;
*/
	:   ( value_value_inheritance_spec )?
	    ( value_interface_inheritance_spec )?
	;

value_value_inheritance_spec
	:   COLON^ ( "truncatable" )?
	    value_name ( COMMA! value_name )*
	;

value_interface_inheritance_spec
	:   "supports"^ interface_name ( COMMA! interface_name )*
	;

value_name
	:   scoped_name
	;

value_element
	:   ( export
	    | state_member
	    | init_dcl
	    )
	;

state_member
	:   ( "public" | "private" )
	    type_spec declarators SEMI!
	;

init_dcl
	:   "factory"^ identifier
	    LPAREN! (init_param_decls)? RPAREN!
	    (raises_expr)?
	    SEMI!
	;

init_param_decls
	:   init_param_decl ( COMMA! init_param_decl )*
	;

init_param_decl
	:   init_param_attribute
	    param_type_spec
	    simple_declarator
	;

init_param_attribute
	:   "in"
	;

const_dcl
	:   "const"^ const_type identifier ASSIGN! const_exp
	;

const_type
	:   (integer_type) => integer_type
	|   char_type
	|   wide_char_type
	|   boolean_type
	|   floating_pt_type
	|   string_type
	|   wide_string_type
	|   fixed_pt_const_type
	|   scoped_name
	|   octet_type
	;


/*   EXPRESSIONS   */

const_exp returns [String literal = null]
	:   literal=or_expr
	;

or_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=xor_expr
	    (  {literal += LT(1).getText();}
	       OR^ // or_op
	       aux=xor_expr
	       {literal += aux;}
	    )*
	;

// or_op
// 	:    OR
// 	;


xor_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=and_expr
	    (
	       {literal += LT(1).getText();}
	       XOR^ // xor_op
	       aux=and_expr
	       {literal += aux;}
	    )*
	;

// xor_op
// 	:    XOR
// 	;

and_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=shift_expr
	    (
	       {literal += LT(1).getText();}
	       AND^ // and_op
	       aux=shift_expr
	       {literal += aux;}
	    )*
	;

// and_op
// 	:    AND
// 	;


shift_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=add_expr
	    (
	       {literal += LT(1).getText();}
	       ( LSHIFT^
	       | RSHIFT^
	       ) // shift_op
	       aux=add_expr
	       {literal += aux;}
	    )*
	;

// shift_op
// 	:    LSHIFT
// 	|    RSHIFT
// 	;


add_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=mult_expr
	    (
	       {literal += LT(1).getText();}
	       ( PLUS^
	       | MINUS^
	       ) // add_op
	       aux=mult_expr
	       {literal += aux;}
	    )*
	;

// add_op
// 	:    PLUS
// 	|    MINUS
// 	;

mult_expr returns [String literal = null]
{
    String aux = null;
}
	:   literal=unary_expr
	    (
	       {literal += LT(1).getText();}
	       ( STAR^
	       | DIV^
	       | MOD^
	       ) // mult_op
	       aux=unary_expr
	       {literal += aux;}
	    )*
	;

// mult_op
// 	:    STAR
// 	|    DIV
// 	|    MOD
// 	;

unary_expr returns [String literal = null]
{
    String aux = null;
}
	:  
	   {literal = LT(1).getText();} 
	   ( MINUS^
	   | PLUS^
	   | TILDE^
	   ) // unary_operator
	    aux=primary_expr
	    {literal += aux;}
	|   literal=primary_expr
	;

// unary_operator
// 	:   MINUS
// 	|   PLUS
// 	|   TILDE
// 	;

// Node of type TPrimaryExp serves to avoid inf. recursion on tree parse
primary_expr returns [String lit = null]
{
    String aux = null;
}
	:   lit=scoped_name
	|   lit=literal
	|  {lit = LT(1).getText();}  
	   LPAREN^
	   aux=const_exp
	   {lit += aux; lit += LT(1).getText();}
	   RPAREN
	;

literal returns [String lit = null]
	:   lit=integer_literal
	|   lit=string_literal
	|   lit=wide_string_literal
	|   lit=character_literal
	|   lit=wide_character_literal
	|   lit=fixed_pt_literal
	|   lit=floating_pt_literal
	|   lit=boolean_literal
	;

boolean_literal returns [String lit = null]
	:   "TRUE"{lit = "true";}
	|   "FALSE"{lit = "false";}
	;

positive_int_const returns [String literal = null]
	:    literal=const_exp
	;


type_dcl returns [TemplateGroup tg = null]
	:   "typedef"^ type_declarator
	|   (struct_type) => tg=struct_type
	|   (union_type) => tg=union_type
	|   enum_type
	|   "native"^ simple_declarator
	|   constr_forward_decl
	;

type_declarator
	:   type_spec declarators
	;

type_spec returns [String literal = null]
	:   literal=simple_type_spec
	|   constr_type_spec
	;

simple_type_spec returns [String literal = null]
	:   literal=base_type_spec
	|   literal=template_type_spec
	|   literal=scoped_name
	;

base_type_spec returns [String literal = null]
	:   (floating_pt_type) => literal=floating_pt_type	
	|   literal=integer_type	
	|   literal=char_type		
	|   literal=wide_char_type		
	|   literal=boolean_type	
	|   literal=octet_type
	|   any_type
	|   object_type
	|   value_base_type
	;

template_type_spec returns [String literal = null]
	:   literal=sequence_type
	|   literal=string_type
	|   literal=wide_string_type
	|   fixed_pt_type
	;

constr_type_spec
	:   struct_type
	|   union_type
	|   enum_type
	;

declarators returns [Vector<Pair<String, StringTemplate>> declvector = new Vector<Pair<String, StringTemplate>>()]
{
    Pair<String, StringTemplate> pair = null;
}
	:   pair=declarator{declvector.add(pair);} (COMMA! pair=declarator{declvector.add(pair);})*
	;

declarator returns [Pair<String, StringTemplate> pair = null]
	:   pair=simple_declarator
	|   pair=complex_declarator
	;

simple_declarator returns [Pair<String, StringTemplate> pair = null]
{
    String name = null;
}
	:  name=identifier
	   {
	       pair = new Pair<String, StringTemplate>(name, tmanager.createStringTemplate("simple_declarator_type"));
	   }
	;

complex_declarator returns [Pair<String, StringTemplate> pair = null]
	:   pair=array_declarator
	;

floating_pt_type returns [String literal = null]
	:   "float"{literal = tmanager.createStringTemplate("float_type").toString();}
	|   "double"{literal = tmanager.createStringTemplate("double_type").toString();}
	|   "long"^ "double"{literal = tmanager.createStringTemplate("long_double_type").toString();}
	;

integer_type returns [String literal = null]
	:  literal=signed_int
	|  literal=unsigned_int
	;

signed_int returns [String literal = null]
	:  literal=signed_short_int
	|  literal=signed_long_int
	|  literal=signed_longlong_int
	;

signed_short_int returns [String literal = tmanager.createStringTemplate("signed_short_int").toString()]
	:  "short"
	;

signed_long_int returns [String literal = tmanager.createStringTemplate("signed_long_int").toString()]
	:  "long"
	;

signed_longlong_int returns [String literal = tmanager.createStringTemplate("signed_longlong_int").toString()]
	:  "long" "long"
	;

unsigned_int returns [String literal = null]
	:  literal=unsigned_short_int
	|  literal=unsigned_long_int
	|  literal=unsigned_longlong_int
	;

unsigned_short_int returns [String literal = tmanager.createStringTemplate("unsigned_short_int").toString()]
	:  "unsigned" "short"
	;

unsigned_long_int returns [String literal = tmanager.createStringTemplate("unsigned_long_int").toString()]
	:  "unsigned" "long"
	;

unsigned_longlong_int returns [String literal = tmanager.createStringTemplate("unsigned_longlong_int").toString()]
	:  "unsigned" "long" "long"
	;

char_type returns [String literal = tmanager.createStringTemplate("char_type").toString()]
	:   "char"
	;

wide_char_type returns [String literal = tmanager.createStringTemplate("wide_char_type").toString()]
	:   "wchar"
	;

boolean_type returns [String literal = tmanager.createStringTemplate("boolean_type").toString()]
	:   "boolean"
	;

octet_type returns [String literal = tmanager.createStringTemplate("octet_type").toString()]
	:   "octet"
	;

any_type
	:   "any"
	;

object_type
	:   "Object"
	;

struct_type returns [TemplateGroup structTemplates = tmanager.createTemplateGroup("struct_type")]
{
    String name = null;
}
	:   "struct"^
	    name=identifier
	    {
	       structTemplates.setAttribute("ctx", ctx);
	       structTemplates.setAttribute("name", name);
	    }
	    LCURLY! member_list[structTemplates] RCURLY!
	;

member_list [TemplateGroup mTemplate]
{
    Vector<Pair<String, StringTemplate>> declvector = null;
}
	:   (
	       declvector=member
	       /* TODO En un futuro cambiar el typelimitation a que los tipos devuelvan un objeto con esta información en vez un String*/
	       {
	           for(int count = 0; count < declvector.size(); ++count)
	               mTemplate.setAttribute("members.{type, name, striptype, typelimitation}", declvector.get(count).second().toString(),
	                   declvector.get(count).first(), TemplateUtil.stripType(declvector.get(count).second().toString()), ctx.getTypelimitation());
	           
	           ctx.setTypelimitation(null);
	       }
	    )+
	;

member returns [Vector<Pair<String, StringTemplate>> declvector = null]
{
    String literal = null;
}
	:  literal=type_spec declvector=declarators SEMI!
	   {
	       for(int count = 0; count < declvector.size(); ++count)
	           declvector.get(count).second().setAttribute("type", literal);
	   }
	;

union_type returns [TemplateGroup unionTemplates = tmanager.createTemplateGroup("union_type")]
{
    List<String> total_labels = null;
    String name = null, dist_type = null;
}
	:   "union"^
	    name=identifier
	    {
           unionTemplates.setAttribute("ctx", ctx);
           unionTemplates.setAttribute("name", name);
        }
	    "switch"! LPAREN! dist_type=switch_type_spec RPAREN!
	    LCURLY! total_labels=switch_body[unionTemplates] RCURLY!
	    {
           unionTemplates.setAttribute("discriminator.{type, name, default}", dist_type, "_d", TemplateUtil.getDefaultLabel(dist_type, total_labels));
        }
	;

switch_type_spec returns [String literal = null]
	:   literal=integer_type
	|   literal=char_type
	|   literal=boolean_type
	|   enum_type
	|   literal=scoped_name
	;

switch_body [TemplateGroup mTemplate] returns [List<String> total_labels = null]
	:   total_labels=case_stmt_list[mTemplate]
	;

case_stmt_list [TemplateGroup mTemplate] returns [List<String> total_labels = new ArrayList<String>()]
{
    List<String> labels = new ArrayList<String>();
}
	:  (labels=case_stmt[mTemplate]{total_labels.addAll(labels);})+
	;

case_stmt [TemplateGroup mTemplate] returns [List<String> labels = new ArrayList<String>()]
{
    Pair<String, StringTemplate> element = null;
    String label = null;
}
	:   // case_label_list
	    ( "case"^ label=const_exp{labels.add(label);} COLON!
	    | "default"^ COLON!
	    )+
	    element=element_spec SEMI!
	    /* TODO En un futuro cambiar el typelimitation a que los tipos devuelvan un objeto con esta información en vez un String*/
	    {
	       mTemplate.setAttribute("elements.{type, name, labels, striptype, typelimitation}", element.second().toString(),
                       element.first(), labels, TemplateUtil.stripType(element.second().toString()), ctx.getTypelimitation());
	    }
	;

// case_label_list
// 	:   (case_label)+
// 	;


// case_label
// 	:   "case"^ const_exp COLON!
// 	|   "default"^ COLON!
// 	;

element_spec returns [Pair<String, StringTemplate> decl = null]
{
    String literal = null;
}
	:   literal=type_spec decl=declarator
	    {
            decl.second().setAttribute("type", literal);
        }
	;

enum_type
	:   "enum"^ identifier LCURLY! enumerator_list RCURLY!
	;

enumerator_list
	:    enumerator (COMMA! enumerator)*
	;

enumerator
	:   identifier
	;

sequence_type returns [String literal = null]
{
    StringTemplate t = tmanager.createStringTemplate("sequence_type");
    String type = null, size = null;
}
	:   "sequence"^
	     LT! type=simple_type_spec{t.setAttribute("type", type);} size=opt_pos_int{ctx.setTypelimitation(size);} GT!
	     {
	       literal = t.toString();
	     }
	;

opt_pos_int returns [String literal = null]
	:    (COMMA! literal=positive_int_const)?
	;

string_type returns [String literal = tmanager.createStringTemplate("string_type").toString()]
{
    String typelimitation = null;
}
	:   "string"^ (LT! typelimitation=positive_int_const {ctx.setTypelimitation(typelimitation);} GT!)?
	;

wide_string_type returns [String literal = tmanager.createStringTemplate("wide_string_type").toString()]
{
    String typelimitation = null;
}
	:   "wstring"^ (LT! typelimitation=positive_int_const {ctx.setTypelimitation(typelimitation);} GT!)?
	;

array_declarator returns [Pair<String, StringTemplate> pair = null]
{
    String name = LT(1).getText(), size = null;
    StringTemplate first = null, second = null;
    String prevf = null, prevs = null;
}
	:   IDENT^					// identifier
	    (
	       size=fixed_array_size
	       {
	           first = tmanager.createStringTemplate("array_declarator_type_first");
	           second = tmanager.createStringTemplate("array_declarator_type_second");
	           second.setAttribute("size", size);
	           
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
	    )+
	    {
	       StringTemplate fin = tmanager.createStringTemplate("array_declarator_type");
	       fin.setAttribute("firs", prevf);
	       fin.setAttribute("secon", prevs);
           pair = new Pair<String, StringTemplate>(name, fin);
        }
	;

fixed_array_size returns [String literal = null]
	:   LBRACK! literal=positive_int_const RBRACK!
	;

attr_dcl
	:   readonly_attr_spec
	|   attr_spec
	;

except_dcl
	:   "exception"^
	    identifier
	    LCURLY! opt_member_list RCURLY!
	;


opt_member_list
	:    (member)*
	;

op_dcl
	:   (op_attribute)?
	    op_type_spec
	    IDENT^				// identifier
	    parameter_dcls
	    (raises_expr)?
	    (context_expr)?
	;

op_attribute
	:   "oneway"
	;

op_type_spec
	:   param_type_spec
	|   "void"
	;

parameter_dcls
	:   LPAREN! (param_dcl_list)? RPAREN!
	;

param_dcl_list
	:   param_dcl (COMMA! param_dcl)*
	;

param_dcl
	:   ("in"^ | "out"^ | "inout"^)		// param_attribute
	    param_type_spec simple_declarator
	;

// param_attribute
// 	:   "in"
// 	|   "out"
// 	|   "inout"
// 	;

raises_expr
	:   "raises"^ LPAREN! scoped_name_list RPAREN!
	;

context_expr
	:   "context"^ LPAREN! string_literal_list RPAREN!
	;

string_literal_list
	:    string_literal (COMMA! string_literal)*
	;

param_type_spec
	:   base_type_spec
	|   string_type
	|   wide_string_type
	|   scoped_name
	;

fixed_pt_type
	:   "fixed"^ LT! positive_int_const COMMA! positive_int_const GT!
	;

fixed_pt_const_type
	:   "fixed"
	;

value_base_type
	:   "ValueBase"
	;

constr_forward_decl
	:   "struct"^ identifier
	|   "union"^ identifier
	;

import_dcl
	:   "import"^ imported_scope SEMI!
	;

imported_scope
	:   scoped_name
	|   string_literal
	;

type_id_dcl
	:   "typeid"^
	    scoped_name
	    string_literal
	;

type_prefix_dcl
	:   "typeprefix"^
	    scoped_name
	    string_literal
	;

readonly_attr_spec
	:   "readonly" "attribute"^
	    param_type_spec
	    readonly_attr_declarator
	;

readonly_attr_declarator
	:   simple_declarator
	    ( raises_expr
	    | (COMMA! simple_declarator)*
	    )
	;

attr_spec
	:   "attribute"^ param_type_spec attr_declarator
	;

attr_declarator
	:   simple_declarator
	    ( ("getraises" | "setraises") => attr_raises_expr
	    | (COMMA! simple_declarator)*
	    )
	;

attr_raises_expr
	:   (get_excep_expr)?
	    (set_excep_expr)?
	;

get_excep_expr
	:   "getraises"^ exception_list
	;

set_excep_expr
	:   "setraises"^ exception_list
	;

exception_list
	:   LPAREN! scoped_name (COMMA! scoped_name)* RPAREN!
	;

// Component Stuff

component
	:   "component"^
	    identifier
	    (component_dcl)?
	;

component_dcl
	:   (component_inheritance_spec)?
	    (supported_interface_spec)?
	    LCURLY! component_body RCURLY!
	;

supported_interface_spec
	:   "supports"^ scoped_name ( COMMA! scoped_name )*
	;

component_inheritance_spec
	:   COLON^ scoped_name
	;

component_body
	:   (component_export)*
	;

component_export
	:   ( provides_dcl SEMI!
	    | uses_dcl SEMI!
	    | emits_dcl SEMI!
	    | publishes_dcl SEMI!
	    | consumes_dcl SEMI!
	    | attr_dcl SEMI!
	    )
	;

provides_dcl
	:   "provides"^ interface_type identifier
	;

interface_type
	:   ( scoped_name
	    | "Object"
	    )
	;

uses_dcl
	:   "uses"^ ("multiple")? interface_type identifier
	;

emits_dcl
	:   "emits"^ scoped_name identifier
	;

publishes_dcl
	:   "publishes"^ scoped_name identifier
	;

consumes_dcl
	:   "consumes"^ scoped_name identifier
	;

home_dcl
	:   home_header home_body
	;

home_header
	:   "home"^ identifier
	    (home_inheritance_spec)?
	    (supported_interface_spec)?
	    "manages"! scoped_name
	    (primary_key_spec)?
	;

home_inheritance_spec
	:   COLON^ scoped_name
	;

primary_key_spec
	:   "primarykey"^ scoped_name
	;

home_body
	:   LCURLY! (home_export)* RCURLY!
	;

home_export
	:   ( export
	    | factory_dcl SEMI!
	    | finder_dcl SEMI!
	    )
	;

factory_dcl
	:   "factory"^ identifier
	    LPAREN! init_param_decls RPAREN!
	    (raises_expr)?
	;

finder_dcl
	:   "finder"^ identifier
	    LPAREN! init_param_decls RPAREN!
	    (raises_expr)?
	;

event
	:   ( event_abs
	    | event_custom
	    | event_dcl
	    )
	;

event_header
	:   "eventtype"^
	    identifier
	;

event_abs
	:   "abstract"^
	    event_header
	    (event_abs_dcl)?
	;

event_abs_dcl
	:   value_inheritance_spec
	    LCURLY! (export)* RCURLY!
	;

event_custom
	:   "custom"^
	    event_header
	    event_elem_dcl
	;

event_dcl
	:   event_header
	    ( event_elem_dcl
	    | // event_forward_dcl
	    )
	;

event_elem_dcl
	:   value_inheritance_spec
	    LCURLY! (export)* RCURLY!
	;

// event_forward_dcl
// 	:
// 	;

/* literals */
integer_literal returns [String literal = LT(1).getText()]
	:   INT
	|   OCTAL
	|   HEX
	;

string_literal returns [String literal = ""]
	:  (
	       {literal += LT(1).getText();}
	       STRING_LITERAL
	   )+
	;

wide_string_literal returns [String literal = ""]
	:  (
	       {literal += LT(1).getText();}
	       WIDE_STRING_LITERAL
	   )+
	;

character_literal returns [String literal = LT(1).getText()]
	:  CHAR_LITERAL
	;

wide_character_literal returns [String literal = LT(1).getText()]
	:  WIDE_CHAR_LITERAL
	;

fixed_pt_literal returns [String literal = LT(1).getText()]
	:  FIXED
	;

floating_pt_literal returns [String literal = LT(1).getText()]
	:   f:FLOAT
	;

identifier returns [String id = LT(1).getText()]
	:   IDENT
	;

/* IDL LEXICAL RULES  */
class IDLLexer extends Lexer;
options {
	exportVocab=IDL;
	charVocabulary='\u0000'..'\uFFFE';
	k=4;
}

SEMI
options {
  paraphrase = ";";
}
	:	';'
	;

QUESTION
options {
  paraphrase = "?";
}
	:	'?'
	;

LPAREN
options {
  paraphrase = "(";
}
	:	'('
	;

RPAREN
options {
  paraphrase = ")";
}
	:	')'
	;

LBRACK
options {
  paraphrase = "[";
}
	:	'['
	;

RBRACK
options {
  paraphrase = "]";
}
	:	']'
	;

LCURLY
options {
  paraphrase = "{";
}
	:	'{'
	;

RCURLY
options {
  paraphrase = "}";
}
	:	'}'
	;

OR
options {
  paraphrase = "|";
}
	:	'|'
	;

XOR
options {
  paraphrase = "^";
}
	:	'^'
	;

AND
options {
  paraphrase = "&";
}
	:	'&'
	;

COLON
options {
  paraphrase = ":";
}
	:	':'
	;

COMMA
options {
  paraphrase = ",";
}
	:	','
	;

DOT
options {
  paraphrase = ".";
}
	:	'.'
	;

ASSIGN
options {
  paraphrase = "=";
}
	:	'='
	;

NOT
options {
  paraphrase = "!";
}
	:	'!'
	;

LT
options {
  paraphrase = "<";
}
	:	'<'
	;

LSHIFT
options {
  paraphrase = "<<";
}
	: "<<"
	;

GT
options {
  paraphrase = ">";
}
	:	'>'
	;

RSHIFT
options {
  paraphrase = ">>";
}
	: ">>"
	;

DIV
options {
  paraphrase = "/";
}
	:	'/'
	;

PLUS
options {
  paraphrase = "+";
}
	:	'+'
	;

MINUS
options {
  paraphrase = "-";
}
	:	'-'
	;

TILDE
options {
  paraphrase = "~";
}
	:	'~'
	;

STAR
options {
  paraphrase = "*";
}
	:	'*'
	;

MOD
options {
  paraphrase = "%";
}
	:	'%'
	;


SCOPEOP
options {
  paraphrase = "::";
}
	:  	"::"
	;

WS
options {
  paraphrase = "white space";
}
	:	(' '
	|	'\t'
	|	'\n'  { newline(); }
	|	'\r')
		{ $setType(Token.SKIP); }
	;


PREPROC_DIRECTIVE
options {
  paraphrase = "a preprocessor directive";
}

	:
	'#'!
	(~'\n')* '\n'!
	{ $setType(Token.SKIP); newline(); }
	;


SL_COMMENT
options {
  paraphrase = "a comment";
}

	:
	"//"!
	(~'\n')* '\n'
	{ $setType(Token.SKIP); newline(); }
	;

ML_COMMENT
options {
  paraphrase = "a comment";
}
	:
	"/*"!
	(
			'\n' { newline(); }
		|	('*')+
			(	'\n' { newline(); }
			|	~('*' | '/' | '\n')
			)
		|	~('*' | '\n')
	)*
	"*/"!
	{ $setType(Token.SKIP);  }
	;

CHAR_LITERAL
options {
  paraphrase = "a character literal";
}
	:
	'\''!
	( ESC | ~'\'' )
	'\''!
	;

WIDE_CHAR_LITERAL
options {
  paraphrase = "a wide character literal";
}
	: 'L'! CHAR_LITERAL
	;

STRING_LITERAL
options {
  paraphrase = "a string literal";
}
	:
	'"'!
	(ESC|~'"')*
	'"'!
	;


WIDE_STRING_LITERAL
options {
  paraphrase = "a wide string literal";
}
	:
	'L'! STRING_LITERAL
	;

protected
ESC
options {
  paraphrase = "an escape sequence";
}
	:	'\\'!
		(	'n'		{$setText("\n");}
		|	't'		{$setText("\t");}
		|	'v'		{$setText("\013");}
		|	'b'		{$setText("\b");}
		|	'r'		{$setText("\r");}
		|	'f'		{$setText("\r");}
		|	'a'  		{$setText("\007");}
		|	'\\'		{$setText("\\");}
		|	'?'     	{$setText("?");}
		|	'\''		{$setText("'");}
		|	'"'		{$setText("\"");}
		|	OCTDIGIT
			(options {greedy=true;}:OCTDIGIT
			  (options {greedy=true;}:OCTDIGIT)?
			)?
			{char realc = (char) Integer.valueOf($getText, 8).intValue(); $setText(realc);}
		|       'x'! HEXDIGIT
			(options {greedy=true;}:HEXDIGIT)?
			{char realc = (char) Integer.valueOf($getText, 16).intValue(); $setText(realc);}
		|	'u'!
			HEXDIGIT
			(options {greedy=true;}:HEXDIGIT
			  (options {greedy=true;}:HEXDIGIT
			    (options {greedy=true;}:HEXDIGIT)?
			  )?
			)?
			{char realc = (char) Integer.valueOf($getText, 16).intValue(); $setText(realc);}
		)
	;

protected
VOCAB
options {
  paraphrase = "an escaped character value";
}
	:	'\3'..'\377'
	;

protected
DIGIT
options {
  paraphrase = "a digit";
}
	:	'0'..'9'
	;

protected
NONZERODIGIT
options {
  paraphrase = "a non-zero digit";
}
	:	'1'..'9'
	;

protected
OCTDIGIT
options {
  paraphrase = "an octal digit";
}
	:	'0'..'7'
	;

protected
HEXDIGIT
options {
  paraphrase = "a hexadecimal digit";
}
	:	('0'..'9' | 'a'..'f' | 'A'..'F')
	;

HEX
options {
  paraphrase = "a hexadecimal value value";
}

	:    ("0x" | "0X") (HEXDIGIT)+
	;

INT
options {
  paraphrase = "an integer value";
}
	:    NONZERODIGIT (DIGIT)*                  // base-10
	     (  '.' (DIGIT)*
		 ( (('e' | 'E') ('+' | '-')? (DIGIT)+)	{$setType(FLOAT);}
		 | ('d' | 'D')!				{$setType(FIXED);}
		 |					{$setType(FLOAT);}
		 )
	     |   ('e' | 'E') ('+' | '-')? (DIGIT)+   	{$setType(FLOAT);}
	     |   ('d' | 'D')!				{$setType(FIXED);}
	     )?
	;

OCTAL
options {
  paraphrase = "an octal value";
}
	:    '0'
	     ( (DIGIT)+
	     | FLOAT					{$setType(FLOAT);}
	     | ('d' | 'D')!				{$setType(FIXED);}
	     |						{$setType(INT);}
	     )
	;


FLOAT
options {
  paraphrase = "a floating point value";
}

	:    '.' (DIGIT)+
	     ( ('e' | 'E') ('+' | '-')? (DIGIT)+
	     | ('d' | 'D')!				{$setType(FIXED);}
	     )?
	;

IDENT
options {
  paraphrase = "an identifer";
  testLiterals = true;
}

	:   ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')*
	;

ESCAPED_IDENT
options {
  paraphrase = "an escaped identifer";
  testLiterals = false;			// redundant, but explicit is good.
}
    // NOTE: Adding a ! to the '_' doesn't seem to work,
    //       so we adjust _begin manually.

	:   '_' ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')*
							{_begin++;$setType(IDENT);}
	;


