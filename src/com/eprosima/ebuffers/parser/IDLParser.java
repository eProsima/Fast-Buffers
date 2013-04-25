// $ANTLR 2.7.7 (20060906): "idl.g" -> "IDLParser.java"$

    package com.eprosima.ebuffers.parser;
    
    import com.eprosima.ebuffers.templates.TemplateManager;
    import com.eprosima.ebuffers.templates.TemplateGroup;
    import com.eprosima.ebuffers.templates.TemplateUtil;
    import com.eprosima.ebuffers.typecode.*;
    import com.eprosima.ebuffers.util.Pair;
    import com.eprosima.ebuffers.Utils;
    
    import org.antlr.stringtemplate.StringTemplate;
   
    import java.util.Vector;
    import java.util.List;
    import java.util.ArrayList;
    import java.util.Map;
    import java.util.HashMap;
 
import antlr.TokenBuffer;
import antlr.TokenStreamException;
import antlr.TokenStreamIOException;
import antlr.ANTLRException;
import antlr.LLkParser;
import antlr.Token;
import antlr.TokenStream;
import antlr.RecognitionException;
import antlr.NoViableAltException;
import antlr.MismatchedTokenException;
import antlr.SemanticException;
import antlr.ParserSharedInputState;
import antlr.collections.impl.BitSet;

public class IDLParser extends antlr.LLkParser       implements IDLTokenTypes
 {
   
    class Context
    {
        public Context(String filename)
        {
            m_filename = filename;
            m_types = new HashMap<String, TypeCode>();
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
        
        public void addTypeCode(String name, TypeCode typecode)
        {
            m_types.put(name, typecode);
        }
        
        public TypeCode getTypeCode(String name)
        {
            int lastIndex = -1;
            TypeCode returnedValue = m_types.get(name);
            
            // Probar si no tiene scope, con el scope acutal.
            if(returnedValue == null && ((lastIndex = name.lastIndexOf("::")) == -1))
            {
                returnedValue = m_types.get(m_scope + name);
            }
            
            return returnedValue;
        }
        
        private String m_filename = "";
        private String m_scope = "";
        private String m_sersym = ">>";
        private String m_typelimitation = null;
        private Map<String, TypeCode> m_types = null;
    }; 
    
    private TemplateManager tmanager = null;
    private Context ctx = null;

protected IDLParser(TokenBuffer tokenBuf, int k) {
  super(tokenBuf,k);
  tokenNames = _tokenNames;
}

public IDLParser(TokenBuffer tokenBuf) {
  this(tokenBuf,4);
}

protected IDLParser(TokenStream lexer, int k) {
  super(lexer,k);
  tokenNames = _tokenNames;
}

public IDLParser(TokenStream lexer) {
  this(lexer,4);
}

public IDLParser(ParserSharedInputState state) {
  super(state,4);
  tokenNames = _tokenNames;
}

	public final boolean  specification(
		String outdir, String idlFilename, boolean replace
	) throws RecognitionException, TokenStreamException {
		boolean returnedValue = false;
		
		
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
		
		
		try {      // for error handling
			{
			_loop3:
			do {
				if ((LA(1)==LITERAL_import)) {
					import_dcl();
				}
				else {
					break _loop3;
				}
				
			} while (true);
			}
			{
			int _cnt5=0;
			_loop5:
			do {
				if ((_tokenSet_0.member(LA(1)))) {
					tg=definition();
					if ( inputState.guessing==0 ) {
						maintemplates.setAttribute("blocks", tg);
					}
				}
				else {
					if ( _cnt5>=1 ) { break _loop5; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt5++;
			} while (true);
			}
			if ( inputState.guessing==0 ) {
				
				if(Utils.writeFile(outdir + idlFilename + ".h", maintemplates.getTemplate("TypesHeader"), replace))
				{
				if(Utils.writeFile(outdir + idlFilename + ".cpp", maintemplates.getTemplate("TypesSource"), replace))
				{
				if(Utils.writeFile(outdir + idlFilename + "CDR.h", maintemplates.getTemplate("CDRHeader"), replace))
				{
				if(Utils.writeFile(outdir + idlFilename + "CDR.cpp", maintemplates.getTemplate("CDRSource"), replace))
				{
				returnedValue = true;
				}
				}
				}
				}
				
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_1);
			} else {
			  throw ex;
			}
		}
		return returnedValue;
	}
	
	public final void import_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_import);
			imported_scope();
			match(SEMI);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_2);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TemplateGroup  definition() throws RecognitionException, TokenStreamException {
		TemplateGroup tg = null;
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_typedef:
			case LITERAL_native:
			case LITERAL_struct:
			case LITERAL_union:
			case LITERAL_enum:
			{
				tg=type_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_const:
			{
				const_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_exception:
			{
				except_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_module:
			{
				tg=module();
				match(SEMI);
				break;
			}
			case LITERAL_typeid:
			{
				type_id_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_typeprefix:
			{
				type_prefix_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_component:
			{
				component();
				match(SEMI);
				break;
			}
			case LITERAL_home:
			{
				home_dcl();
				match(SEMI);
				break;
			}
			default:
				boolean synPredMatched10 = false;
				if ((((LA(1) >= LITERAL_abstract && LA(1) <= LITERAL_interface)) && (LA(2)==LITERAL_interface||LA(2)==IDENT) && (_tokenSet_3.member(LA(3))) && (_tokenSet_4.member(LA(4))))) {
					int _m10 = mark();
					synPredMatched10 = true;
					inputState.guessing++;
					try {
						{
						{
						switch ( LA(1)) {
						case LITERAL_abstract:
						{
							match(LITERAL_abstract);
							break;
						}
						case LITERAL_local:
						{
							match(LITERAL_local);
							break;
						}
						case LITERAL_interface:
						{
							break;
						}
						default:
						{
							throw new NoViableAltException(LT(1), getFilename());
						}
						}
						}
						match(LITERAL_interface);
						}
					}
					catch (RecognitionException pe) {
						synPredMatched10 = false;
					}
					rewind(_m10);
inputState.guessing--;
				}
				if ( synPredMatched10 ) {
					interf();
					match(SEMI);
				}
				else {
					boolean synPredMatched13 = false;
					if (((LA(1)==LITERAL_abstract||LA(1)==LITERAL_custom||LA(1)==LITERAL_valuetype) && (LA(2)==LITERAL_valuetype||LA(2)==IDENT) && (_tokenSet_5.member(LA(3))) && (_tokenSet_6.member(LA(4))))) {
						int _m13 = mark();
						synPredMatched13 = true;
						inputState.guessing++;
						try {
							{
							{
							switch ( LA(1)) {
							case LITERAL_abstract:
							{
								match(LITERAL_abstract);
								break;
							}
							case LITERAL_custom:
							{
								match(LITERAL_custom);
								break;
							}
							case LITERAL_valuetype:
							{
								break;
							}
							default:
							{
								throw new NoViableAltException(LT(1), getFilename());
							}
							}
							}
							match(LITERAL_valuetype);
							}
						}
						catch (RecognitionException pe) {
							synPredMatched13 = false;
						}
						rewind(_m13);
inputState.guessing--;
					}
					if ( synPredMatched13 ) {
						value();
						match(SEMI);
					}
					else {
						boolean synPredMatched16 = false;
						if (((LA(1)==LITERAL_abstract||LA(1)==LITERAL_custom||LA(1)==LITERAL_eventtype) && (LA(2)==LITERAL_eventtype||LA(2)==IDENT) && (_tokenSet_7.member(LA(3))) && (_tokenSet_8.member(LA(4))))) {
							int _m16 = mark();
							synPredMatched16 = true;
							inputState.guessing++;
							try {
								{
								{
								switch ( LA(1)) {
								case LITERAL_abstract:
								{
									match(LITERAL_abstract);
									break;
								}
								case LITERAL_custom:
								{
									match(LITERAL_custom);
									break;
								}
								case LITERAL_eventtype:
								{
									break;
								}
								default:
								{
									throw new NoViableAltException(LT(1), getFilename());
								}
								}
								}
								match(LITERAL_eventtype);
								}
							}
							catch (RecognitionException pe) {
								synPredMatched16 = false;
							}
							rewind(_m16);
inputState.guessing--;
						}
						if ( synPredMatched16 ) {
							event();
							match(SEMI);
						}
					else {
						throw new NoViableAltException(LT(1), getFilename());
					}
					}}}
					}
				}
				catch (RecognitionException ex) {
					if (inputState.guessing==0) {
						reportError(ex);
						recover(ex,_tokenSet_9);
					} else {
					  throw ex;
					}
				}
				return tg;
			}
			
	public final TemplateGroup  type_dcl() throws RecognitionException, TokenStreamException {
		TemplateGroup tg = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_typedef:
			{
				match(LITERAL_typedef);
				type_declarator();
				break;
			}
			case LITERAL_enum:
			{
				tg=enum_type();
				break;
			}
			case LITERAL_native:
			{
				match(LITERAL_native);
				simple_declarator();
				break;
			}
			default:
				boolean synPredMatched114 = false;
				if (((LA(1)==LITERAL_struct) && (LA(2)==IDENT) && (LA(3)==LCURLY))) {
					int _m114 = mark();
					synPredMatched114 = true;
					inputState.guessing++;
					try {
						{
						struct_type();
						}
					}
					catch (RecognitionException pe) {
						synPredMatched114 = false;
					}
					rewind(_m114);
inputState.guessing--;
				}
				if ( synPredMatched114 ) {
					tg=struct_type();
				}
				else {
					boolean synPredMatched116 = false;
					if (((LA(1)==LITERAL_union) && (LA(2)==IDENT) && (LA(3)==LITERAL_switch))) {
						int _m116 = mark();
						synPredMatched116 = true;
						inputState.guessing++;
						try {
							{
							union_type();
							}
						}
						catch (RecognitionException pe) {
							synPredMatched116 = false;
						}
						rewind(_m116);
inputState.guessing--;
					}
					if ( synPredMatched116 ) {
						tg=union_type();
					}
					else if ((LA(1)==LITERAL_struct||LA(1)==LITERAL_union) && (LA(2)==IDENT) && (LA(3)==SEMI)) {
						constr_forward_decl();
					}
				else {
					throw new NoViableAltException(LT(1), getFilename());
				}
				}}
			}
			catch (RecognitionException ex) {
				if (inputState.guessing==0) {
					reportError(ex);
					recover(ex,_tokenSet_10);
				} else {
				  throw ex;
				}
			}
			return tg;
		}
		
	public final void const_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_const);
			const_type();
			identifier();
			match(ASSIGN);
			const_exp();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void except_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_exception);
			identifier();
			match(LCURLY);
			opt_member_list();
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void interf() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			if (((LA(1) >= LITERAL_abstract && LA(1) <= LITERAL_interface)) && (LA(2)==LITERAL_interface||LA(2)==IDENT) && (LA(3)==LCURLY||LA(3)==COLON||LA(3)==IDENT) && (_tokenSet_11.member(LA(4)))) {
				interface_dcl();
			}
			else if (((LA(1) >= LITERAL_abstract && LA(1) <= LITERAL_interface)) && (LA(2)==LITERAL_interface||LA(2)==IDENT) && (LA(3)==SEMI||LA(3)==IDENT) && (_tokenSet_12.member(LA(4)))) {
				forward_dcl();
			}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TemplateGroup  module() throws RecognitionException, TokenStreamException {
		TemplateGroup moduleTemplates = tmanager.createTemplateGroup("module");
		
		
		TemplateGroup tg = null;
		String name = null, old_scope = ctx.getScope();
		
		
		try {      // for error handling
			match(LITERAL_module);
			name=identifier();
			if ( inputState.guessing==0 ) {
				
					       moduleTemplates.setAttribute("name", name);
					       ctx.setScope(old_scope + name + "::");
					
			}
			match(LCURLY);
			tg=definition_list();
			if ( inputState.guessing==0 ) {
				moduleTemplates.setAttribute("definition_list", tg);
			}
			match(RCURLY);
			if ( inputState.guessing==0 ) {
				
					       ctx.setScope(old_scope);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
		return moduleTemplates;
	}
	
	public final void value() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_abstract:
			{
				value_abs_dcl();
				break;
			}
			case LITERAL_custom:
			{
				value_custom_dcl();
				break;
			}
			default:
				if ((LA(1)==LITERAL_valuetype) && (LA(2)==IDENT) && (LA(3)==LCURLY||LA(3)==COLON||LA(3)==LITERAL_supports)) {
					value_dcl();
				}
				else if ((LA(1)==LITERAL_valuetype) && (LA(2)==IDENT) && (_tokenSet_13.member(LA(3)))) {
					value_box_dcl();
				}
				else if ((LA(1)==LITERAL_valuetype) && (LA(2)==IDENT) && (LA(3)==SEMI)) {
					value_forward_dcl();
				}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void type_id_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_typeid);
			scoped_name();
			string_literal();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void type_prefix_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_typeprefix);
			scoped_name();
			string_literal();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_abstract:
			{
				event_abs();
				break;
			}
			case LITERAL_custom:
			{
				event_custom();
				break;
			}
			case LITERAL_eventtype:
			{
				event_dcl();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void component() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_component);
			identifier();
			{
			switch ( LA(1)) {
			case LCURLY:
			case COLON:
			case LITERAL_supports:
			{
				component_dcl();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void home_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			home_header();
			home_body();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final String  identifier() throws RecognitionException, TokenStreamException {
		String id = LT(1).getText();
		
		
		try {      // for error handling
			match(IDENT);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_14);
			} else {
			  throw ex;
			}
		}
		return id;
	}
	
	public final TemplateGroup  definition_list() throws RecognitionException, TokenStreamException {
		TemplateGroup dlTemplates = tmanager.createTemplateGroup("definition_list");
		
		
		TemplateGroup tg = null;
		
		
		try {      // for error handling
			{
			int _cnt20=0;
			_loop20:
			do {
				if ((_tokenSet_0.member(LA(1)))) {
					tg=definition();
					if ( inputState.guessing==0 ) {
						dlTemplates.setAttribute("definitions", tg);
					}
				}
				else {
					if ( _cnt20>=1 ) { break _loop20; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt20++;
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
		return dlTemplates;
	}
	
	public final void interface_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			{
			switch ( LA(1)) {
			case LITERAL_abstract:
			{
				match(LITERAL_abstract);
				break;
			}
			case LITERAL_local:
			{
				match(LITERAL_local);
				break;
			}
			case LITERAL_interface:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(LITERAL_interface);
			identifier();
			{
			switch ( LA(1)) {
			case COLON:
			{
				interface_inheritance_spec();
				break;
			}
			case LCURLY:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(LCURLY);
			interface_body();
			match(RCURLY);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void forward_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_abstract:
			{
				match(LITERAL_abstract);
				break;
			}
			case LITERAL_local:
			{
				match(LITERAL_local);
				break;
			}
			case LITERAL_interface:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(LITERAL_interface);
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void interface_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(COLON);
			scoped_name_list();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void interface_body() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			_loop31:
			do {
				if ((_tokenSet_17.member(LA(1)))) {
					export();
				}
				else {
					break _loop31;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void export() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_typedef:
			case LITERAL_native:
			case LITERAL_struct:
			case LITERAL_union:
			case LITERAL_enum:
			{
				type_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_const:
			{
				const_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_exception:
			{
				except_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_readonly:
			case LITERAL_attribute:
			{
				attr_dcl();
				match(SEMI);
				break;
			}
			case SCOPEOP:
			case IDENT:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_oneway:
			case LITERAL_void:
			case LITERAL_ValueBase:
			{
				op_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_typeid:
			{
				type_id_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_typeprefix:
			{
				type_prefix_dcl();
				match(SEMI);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_18);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void attr_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_readonly:
			{
				readonly_attr_spec();
				break;
			}
			case LITERAL_attribute:
			{
				attr_spec();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void op_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_oneway:
			{
				op_attribute();
				break;
			}
			case SCOPEOP:
			case IDENT:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_void:
			case LITERAL_ValueBase:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			op_type_spec();
			match(IDENT);
			parameter_dcls();
			{
			switch ( LA(1)) {
			case LITERAL_raises:
			{
				raises_expr();
				break;
			}
			case SEMI:
			case LITERAL_context:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LITERAL_context:
			{
				context_expr();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void scoped_name_list() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			scoped_name();
			{
			_loop38:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					scoped_name();
				}
				else {
					break _loop38;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_19);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void interface_name() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			scoped_name();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_20);
			} else {
			  throw ex;
			}
		}
	}
	
	public final String  scoped_name() throws RecognitionException, TokenStreamException {
		String literal = "";
		
		
		String aux = null;
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case SCOPEOP:
			{
				if ( inputState.guessing==0 ) {
					literal += LT(1).getText();
				}
				match(SCOPEOP);
				break;
			}
			case IDENT:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			if ( inputState.guessing==0 ) {
				literal += LT(1).getText();
			}
			match(IDENT);
			{
			_loop42:
			do {
				if ((LA(1)==SCOPEOP)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(SCOPEOP);
					aux=identifier();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop42;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_21);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final void value_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			value_header();
			match(LCURLY);
			{
			_loop54:
			do {
				if ((_tokenSet_22.member(LA(1)))) {
					value_element();
				}
				else {
					break _loop54;
				}
				
			} while (true);
			}
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_abs_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_abstract);
			match(LITERAL_valuetype);
			identifier();
			{
			switch ( LA(1)) {
			case LCURLY:
			case COLON:
			case LITERAL_supports:
			{
				value_abs_full_dcl();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_box_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_valuetype);
			identifier();
			type_spec();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_custom_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_custom);
			value_dcl();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_forward_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_valuetype);
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TypeCode  type_spec() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_sequence:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_fixed:
			case LITERAL_ValueBase:
			{
				typecode=simple_type_spec();
				break;
			}
			case LITERAL_struct:
			case LITERAL_union:
			case LITERAL_enum:
			{
				constr_type_spec();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_23);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void value_abs_full_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			value_inheritance_spec();
			match(LCURLY);
			{
			_loop51:
			do {
				if ((_tokenSet_17.member(LA(1)))) {
					export();
				}
				else {
					break _loop51;
				}
				
			} while (true);
			}
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case COLON:
			{
				value_value_inheritance_spec();
				break;
			}
			case LCURLY:
			case LITERAL_supports:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LITERAL_supports:
			{
				value_interface_inheritance_spec();
				break;
			}
			case LCURLY:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_header() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_valuetype);
			identifier();
			value_inheritance_spec();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_element() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			case LITERAL_const:
			case LITERAL_typedef:
			case LITERAL_native:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_struct:
			case LITERAL_union:
			case LITERAL_enum:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_exception:
			case LITERAL_oneway:
			case LITERAL_void:
			case LITERAL_ValueBase:
			case LITERAL_typeid:
			case LITERAL_typeprefix:
			case LITERAL_readonly:
			case LITERAL_attribute:
			{
				export();
				break;
			}
			case LITERAL_public:
			case LITERAL_private:
			{
				state_member();
				break;
			}
			case LITERAL_factory:
			{
				init_dcl();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_24);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_value_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(COLON);
			{
			switch ( LA(1)) {
			case LITERAL_truncatable:
			{
				match(LITERAL_truncatable);
				break;
			}
			case SCOPEOP:
			case IDENT:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			value_name();
			{
			_loop63:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					value_name();
				}
				else {
					break _loop63;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_25);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_interface_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_supports);
			interface_name();
			{
			_loop66:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					interface_name();
				}
				else {
					break _loop66;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_name() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			scoped_name();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_26);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void state_member() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_public:
			{
				match(LITERAL_public);
				break;
			}
			case LITERAL_private:
			{
				match(LITERAL_private);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			type_spec();
			declarators();
			match(SEMI);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_24);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void init_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_factory);
			identifier();
			match(LPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_in:
			{
				init_param_decls();
				break;
			}
			case RPAREN:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(RPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_raises:
			{
				raises_expr();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(SEMI);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_24);
			} else {
			  throw ex;
			}
		}
	}
	
	public final Vector<Pair<String, ContainerTypeCode>>  declarators() throws RecognitionException, TokenStreamException {
		Vector<Pair<String, ContainerTypeCode>> declvector = new Vector<Pair<String, ContainerTypeCode>>();
		
		
		Pair<String, ContainerTypeCode> pair = null;
		
		
		try {      // for error handling
			pair=declarator();
			if ( inputState.guessing==0 ) {
				declvector.add(pair);
			}
			{
			_loop127:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					pair=declarator();
					if ( inputState.guessing==0 ) {
						declvector.add(pair);
					}
				}
				else {
					break _loop127;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
		return declvector;
	}
	
	public final void init_param_decls() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			init_param_decl();
			{
			_loop77:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					init_param_decl();
				}
				else {
					break _loop77;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_27);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void raises_expr() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_raises);
			match(LPAREN);
			scoped_name_list();
			match(RPAREN);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_28);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void init_param_decl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			init_param_attribute();
			param_type_spec();
			simple_declarator();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_29);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void init_param_attribute() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_in);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_30);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void param_type_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_ValueBase:
			{
				base_type_spec();
				break;
			}
			case LITERAL_string:
			{
				string_type();
				break;
			}
			case LITERAL_wstring:
			{
				wide_string_type();
				break;
			}
			case SCOPEOP:
			case IDENT:
			{
				scoped_name();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_31);
			} else {
			  throw ex;
			}
		}
	}
	
	public final Pair<String, ContainerTypeCode>  simple_declarator() throws RecognitionException, TokenStreamException {
		Pair<String, ContainerTypeCode> pair = null;
		
		
		String name = null;
		
		
		try {      // for error handling
			name=identifier();
			if ( inputState.guessing==0 ) {
				
					       pair = new Pair<String, ContainerTypeCode>(name, null);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_32);
			} else {
			  throw ex;
			}
		}
		return pair;
	}
	
	public final void const_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_char:
			{
				char_type();
				break;
			}
			case LITERAL_wchar:
			{
				wide_char_type();
				break;
			}
			case LITERAL_boolean:
			{
				boolean_type();
				break;
			}
			case LITERAL_string:
			{
				string_type();
				break;
			}
			case LITERAL_wstring:
			{
				wide_string_type();
				break;
			}
			case LITERAL_fixed:
			{
				fixed_pt_const_type();
				break;
			}
			case SCOPEOP:
			case IDENT:
			{
				scoped_name();
				break;
			}
			case LITERAL_octet:
			{
				octet_type();
				break;
			}
			default:
				boolean synPredMatched83 = false;
				if ((((LA(1) >= LITERAL_long && LA(1) <= LITERAL_unsigned)) && (LA(2)==IDENT||LA(2)==LITERAL_long||LA(2)==LITERAL_short) && (LA(3)==IDENT||LA(3)==ASSIGN||LA(3)==LITERAL_long) && (_tokenSet_33.member(LA(4))))) {
					int _m83 = mark();
					synPredMatched83 = true;
					inputState.guessing++;
					try {
						{
						integer_type();
						}
					}
					catch (RecognitionException pe) {
						synPredMatched83 = false;
					}
					rewind(_m83);
inputState.guessing--;
				}
				if ( synPredMatched83 ) {
					integer_type();
				}
				else if (((LA(1) >= LITERAL_float && LA(1) <= LITERAL_long)) && (LA(2)==IDENT||LA(2)==LITERAL_double) && (LA(3)==IDENT||LA(3)==ASSIGN) && (_tokenSet_33.member(LA(4)))) {
					floating_pt_type();
				}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_31);
			} else {
			  throw ex;
			}
		}
	}
	
	public final String  const_exp() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		try {      // for error handling
			literal=or_expr();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_34);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final TypeCode  integer_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_long:
			case LITERAL_short:
			{
				typecode=signed_int();
				break;
			}
			case LITERAL_unsigned:
			{
				typecode=unsigned_int();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  char_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_CHAR);
		
		
		try {      // for error handling
			match(LITERAL_char);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  wide_char_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_WCHAR);
		
		
		try {      // for error handling
			match(LITERAL_wchar);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  boolean_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_BOOLEAN);
		
		
		try {      // for error handling
			match(LITERAL_boolean);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  floating_pt_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_float:
			{
				match(LITERAL_float);
				if ( inputState.guessing==0 ) {
					typecode = new PrimitiveTypeCode(TypeCode.KIND_FLOAT);
				}
				break;
			}
			case LITERAL_double:
			{
				match(LITERAL_double);
				if ( inputState.guessing==0 ) {
					typecode = new PrimitiveTypeCode(TypeCode.KIND_DOUBLE);
				}
				break;
			}
			case LITERAL_long:
			{
				match(LITERAL_long);
				match(LITERAL_double);
				if ( inputState.guessing==0 ) {
					typecode = new PrimitiveTypeCode(TypeCode.KIND_LONGDOUBLE);
				}
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  string_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		String maxsize = null;
		
		
		try {      // for error handling
			match(LITERAL_string);
			{
			switch ( LA(1)) {
			case LT:
			{
				match(LT);
				maxsize=positive_int_const();
				match(GT);
				break;
			}
			case SEMI:
			case COMMA:
			case IDENT:
			case GT:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			if ( inputState.guessing==0 ) {
				typecode = new StringTypeCode(TypeCode.KIND_STRING, maxsize);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  wide_string_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		String maxsize = null;
		
		
		try {      // for error handling
			match(LITERAL_wstring);
			{
			switch ( LA(1)) {
			case LT:
			{
				match(LT);
				maxsize=positive_int_const();
				match(GT);
				break;
			}
			case SEMI:
			case COMMA:
			case IDENT:
			case GT:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			if ( inputState.guessing==0 ) {
				typecode = new StringTypeCode(TypeCode.KIND_WSTRING, maxsize);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void fixed_pt_const_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_fixed);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_31);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TypeCode  octet_type() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_OCTET);
		
		
		try {      // for error handling
			match(LITERAL_octet);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final String  or_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=xor_expr();
			{
			_loop87:
			do {
				if ((LA(1)==OR)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(OR);
					aux=xor_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop87;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_34);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  xor_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=and_expr();
			{
			_loop90:
			do {
				if ((LA(1)==XOR)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(XOR);
					aux=and_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop90;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_37);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  and_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=shift_expr();
			{
			_loop93:
			do {
				if ((LA(1)==AND)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(AND);
					aux=shift_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop93;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_38);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  shift_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=add_expr();
			{
			_loop97:
			do {
				if ((LA(1)==LSHIFT||LA(1)==RSHIFT)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					{
					switch ( LA(1)) {
					case LSHIFT:
					{
						match(LSHIFT);
						break;
					}
					case RSHIFT:
					{
						match(RSHIFT);
						break;
					}
					default:
					{
						throw new NoViableAltException(LT(1), getFilename());
					}
					}
					}
					aux=add_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop97;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_39);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  add_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=mult_expr();
			{
			_loop101:
			do {
				if ((LA(1)==PLUS||LA(1)==MINUS)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					{
					switch ( LA(1)) {
					case PLUS:
					{
						match(PLUS);
						break;
					}
					case MINUS:
					{
						match(MINUS);
						break;
					}
					default:
					{
						throw new NoViableAltException(LT(1), getFilename());
					}
					}
					}
					aux=mult_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop101;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_40);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  mult_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			literal=unary_expr();
			{
			_loop105:
			do {
				if (((LA(1) >= STAR && LA(1) <= MOD))) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					{
					switch ( LA(1)) {
					case STAR:
					{
						match(STAR);
						break;
					}
					case DIV:
					{
						match(DIV);
						break;
					}
					case MOD:
					{
						match(MOD);
						break;
					}
					default:
					{
						throw new NoViableAltException(LT(1), getFilename());
					}
					}
					}
					aux=unary_expr();
					if ( inputState.guessing==0 ) {
						literal += aux;
					}
				}
				else {
					break _loop105;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_41);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  unary_expr() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case PLUS:
			case MINUS:
			case TILDE:
			{
				if ( inputState.guessing==0 ) {
					literal = LT(1).getText();
				}
				{
				switch ( LA(1)) {
				case MINUS:
				{
					match(MINUS);
					break;
				}
				case PLUS:
				{
					match(PLUS);
					break;
				}
				case TILDE:
				{
					match(TILDE);
					break;
				}
				default:
				{
					throw new NoViableAltException(LT(1), getFilename());
				}
				}
				}
				aux=primary_expr();
				if ( inputState.guessing==0 ) {
					literal += aux;
				}
				break;
			}
			case SCOPEOP:
			case IDENT:
			case LPAREN:
			case LITERAL_TRUE:
			case LITERAL_FALSE:
			case INT:
			case OCTAL:
			case HEX:
			case STRING_LITERAL:
			case WIDE_STRING_LITERAL:
			case CHAR_LITERAL:
			case WIDE_CHAR_LITERAL:
			case FIXED:
			case FLOAT:
			{
				literal=primary_expr();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  primary_expr() throws RecognitionException, TokenStreamException {
		String lit = null;
		
		
		String aux = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			{
				lit=scoped_name();
				break;
			}
			case LITERAL_TRUE:
			case LITERAL_FALSE:
			case INT:
			case OCTAL:
			case HEX:
			case STRING_LITERAL:
			case WIDE_STRING_LITERAL:
			case CHAR_LITERAL:
			case WIDE_CHAR_LITERAL:
			case FIXED:
			case FLOAT:
			{
				lit=literal();
				break;
			}
			case LPAREN:
			{
				if ( inputState.guessing==0 ) {
					lit = LT(1).getText();
				}
				match(LPAREN);
				aux=const_exp();
				if ( inputState.guessing==0 ) {
					lit += aux; lit += LT(1).getText();
				}
				match(RPAREN);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return lit;
	}
	
	public final String  literal() throws RecognitionException, TokenStreamException {
		String lit = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case INT:
			case OCTAL:
			case HEX:
			{
				lit=integer_literal();
				break;
			}
			case STRING_LITERAL:
			{
				lit=string_literal();
				break;
			}
			case WIDE_STRING_LITERAL:
			{
				lit=wide_string_literal();
				break;
			}
			case CHAR_LITERAL:
			{
				lit=character_literal();
				break;
			}
			case WIDE_CHAR_LITERAL:
			{
				lit=wide_character_literal();
				break;
			}
			case FIXED:
			{
				lit=fixed_pt_literal();
				break;
			}
			case FLOAT:
			{
				lit=floating_pt_literal();
				break;
			}
			case LITERAL_TRUE:
			case LITERAL_FALSE:
			{
				lit=boolean_literal();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return lit;
	}
	
	public final String  integer_literal() throws RecognitionException, TokenStreamException {
		String literal = LT(1).getText();
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case INT:
			{
				match(INT);
				break;
			}
			case OCTAL:
			{
				match(OCTAL);
				break;
			}
			case HEX:
			{
				match(HEX);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  string_literal() throws RecognitionException, TokenStreamException {
		String literal = "";
		
		
		try {      // for error handling
			{
			int _cnt285=0;
			_loop285:
			do {
				if ((LA(1)==STRING_LITERAL)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(STRING_LITERAL);
				}
				else {
					if ( _cnt285>=1 ) { break _loop285; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt285++;
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  wide_string_literal() throws RecognitionException, TokenStreamException {
		String literal = "";
		
		
		try {      // for error handling
			{
			int _cnt288=0;
			_loop288:
			do {
				if ((LA(1)==WIDE_STRING_LITERAL)) {
					if ( inputState.guessing==0 ) {
						literal += LT(1).getText();
					}
					match(WIDE_STRING_LITERAL);
				}
				else {
					if ( _cnt288>=1 ) { break _loop288; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt288++;
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  character_literal() throws RecognitionException, TokenStreamException {
		String literal = LT(1).getText();
		
		
		try {      // for error handling
			match(CHAR_LITERAL);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  wide_character_literal() throws RecognitionException, TokenStreamException {
		String literal = LT(1).getText();
		
		
		try {      // for error handling
			match(WIDE_CHAR_LITERAL);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  fixed_pt_literal() throws RecognitionException, TokenStreamException {
		String literal = LT(1).getText();
		
		
		try {      // for error handling
			match(FIXED);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  floating_pt_literal() throws RecognitionException, TokenStreamException {
		String literal = LT(1).getText();
		
		Token  f = null;
		
		try {      // for error handling
			f = LT(1);
			match(FLOAT);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  boolean_literal() throws RecognitionException, TokenStreamException {
		String lit = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_TRUE:
			{
				match(LITERAL_TRUE);
				if ( inputState.guessing==0 ) {
					lit = "true";
				}
				break;
			}
			case LITERAL_FALSE:
			{
				match(LITERAL_FALSE);
				if ( inputState.guessing==0 ) {
					lit = "false";
				}
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_42);
			} else {
			  throw ex;
			}
		}
		return lit;
	}
	
	public final String  positive_int_const() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		try {      // for error handling
			literal=const_exp();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_43);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final void type_declarator() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			type_spec();
			declarators();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TemplateGroup  struct_type() throws RecognitionException, TokenStreamException {
		TemplateGroup structTemplates = tmanager.createTemplateGroup("struct_type");
		
		
		String name = null;
		StructTypeCode structTP = null;
		
		
		try {      // for error handling
			match(LITERAL_struct);
			name=identifier();
			if ( inputState.guessing==0 ) {
				
					       structTP = new StructTypeCode(ctx.getScope(), name);
					
			}
			match(LCURLY);
			member_list(structTP);
			match(RCURLY);
			if ( inputState.guessing==0 ) {
				
					       structTemplates.setAttribute("ctx", ctx);
				structTemplates.setAttribute("struct", structTP);
				// Add struct typecode to the map with all typecodes.
				ctx.addTypeCode(structTP.getScopedname(), structTP);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_23);
			} else {
			  throw ex;
			}
		}
		return structTemplates;
	}
	
	public final TemplateGroup  union_type() throws RecognitionException, TokenStreamException {
		TemplateGroup unionTemplates = tmanager.createTemplateGroup("union_type");
		
		
		String name = null;
		TypeCode dist_type = null;
		UnionTypeCode unionTP = null;
		
		
		try {      // for error handling
			match(LITERAL_union);
			name=identifier();
			match(LITERAL_switch);
			match(LPAREN);
			dist_type=switch_type_spec();
			match(RPAREN);
			if ( inputState.guessing==0 ) {
				
					       unionTP = new UnionTypeCode(ctx.getScope(), name, dist_type);
					
			}
			match(LCURLY);
			switch_body(unionTP);
			match(RCURLY);
			if ( inputState.guessing==0 ) {
				
					       // Calculate default label.
					       unionTP.setDefaultvalue(TemplateUtil.getUnionDefaultLabel(unionTP.getDiscriminator(), unionTP.getMembers()));
					       unionTemplates.setAttribute("ctx", ctx);
				unionTemplates.setAttribute("union", unionTP);
				
				// Add union typecode to the map with all typecodes.
				ctx.addTypeCode(unionTP.getScopedname(), unionTP);
				
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_23);
			} else {
			  throw ex;
			}
		}
		return unionTemplates;
	}
	
	public final TemplateGroup  enum_type() throws RecognitionException, TokenStreamException {
		TemplateGroup enumTemplates = tmanager.createTemplateGroup("enum_type");
		
		
		String name = null;
		EnumTypeCode enumTP = null;
		
		
		try {      // for error handling
			match(LITERAL_enum);
			name=identifier();
			if ( inputState.guessing==0 ) {
				
					       enumTP = new EnumTypeCode(ctx.getScope(), name);
					
			}
			match(LCURLY);
			enumerator_list(enumTP);
			match(RCURLY);
			if ( inputState.guessing==0 ) {
				
				enumTemplates.setAttribute("ctx", ctx);
				enumTemplates.setAttribute("enum", enumTP);
				// Add enum typecode to the map with all typecodes.
				ctx.addTypeCode(enumTP.getScopedname(), enumTP);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_44);
			} else {
			  throw ex;
			}
		}
		return enumTemplates;
	}
	
	public final void constr_forward_decl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_struct:
			{
				match(LITERAL_struct);
				identifier();
				break;
			}
			case LITERAL_union:
			{
				match(LITERAL_union);
				identifier();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TypeCode  simple_type_spec() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		String literal = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_ValueBase:
			{
				typecode=base_type_spec();
				break;
			}
			case LITERAL_sequence:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_fixed:
			{
				typecode=template_type_spec();
				break;
			}
			case SCOPEOP:
			case IDENT:
			{
				literal=scoped_name();
				if ( inputState.guessing==0 ) {
					
						       // Find typecode in the global map.
						       typecode = ctx.getTypeCode(literal);
						       
						       if(typecode == null)
						           System.out.println("ERROR: Cannot find the typecode for " + literal);
						
				}
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void constr_type_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_struct:
			{
				struct_type();
				break;
			}
			case LITERAL_union:
			{
				union_type();
				break;
			}
			case LITERAL_enum:
			{
				enum_type();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_23);
			} else {
			  throw ex;
			}
		}
	}
	
	public final TypeCode  base_type_spec() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_char:
			{
				typecode=char_type();
				break;
			}
			case LITERAL_wchar:
			{
				typecode=wide_char_type();
				break;
			}
			case LITERAL_boolean:
			{
				typecode=boolean_type();
				break;
			}
			case LITERAL_octet:
			{
				typecode=octet_type();
				break;
			}
			case LITERAL_any:
			{
				any_type();
				break;
			}
			case LITERAL_Object:
			{
				object_type();
				break;
			}
			case LITERAL_ValueBase:
			{
				value_base_type();
				break;
			}
			default:
				boolean synPredMatched122 = false;
				if ((((LA(1) >= LITERAL_float && LA(1) <= LITERAL_long)) && (_tokenSet_45.member(LA(2))) && (_tokenSet_46.member(LA(3))) && (_tokenSet_47.member(LA(4))))) {
					int _m122 = mark();
					synPredMatched122 = true;
					inputState.guessing++;
					try {
						{
						floating_pt_type();
						}
					}
					catch (RecognitionException pe) {
						synPredMatched122 = false;
					}
					rewind(_m122);
inputState.guessing--;
				}
				if ( synPredMatched122 ) {
					typecode=floating_pt_type();
				}
				else if (((LA(1) >= LITERAL_long && LA(1) <= LITERAL_unsigned)) && (_tokenSet_48.member(LA(2))) && (_tokenSet_49.member(LA(3))) && (_tokenSet_47.member(LA(4)))) {
					typecode=integer_type();
				}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  template_type_spec() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_sequence:
			{
				typecode=sequence_type();
				break;
			}
			case LITERAL_string:
			{
				typecode=string_type();
				break;
			}
			case LITERAL_wstring:
			{
				typecode=wide_string_type();
				break;
			}
			case LITERAL_fixed:
			{
				fixed_pt_type();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void any_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_any);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void object_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_Object);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void value_base_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_ValueBase);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
	}
	
	public final SequenceTypeCode  sequence_type() throws RecognitionException, TokenStreamException {
		SequenceTypeCode typecode = null;
		
		
		TypeCode type = null;
		String maxsize = null;
		
		
		try {      // for error handling
			match(LITERAL_sequence);
			match(LT);
			type=simple_type_spec();
			maxsize=opt_pos_int();
			match(GT);
			if ( inputState.guessing==0 ) {
				
					       typecode = new SequenceTypeCode(maxsize);
					       typecode.setContentTypeCode(type);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void fixed_pt_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_fixed);
			match(LT);
			positive_int_const();
			match(COMMA);
			positive_int_const();
			match(GT);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_36);
			} else {
			  throw ex;
			}
		}
	}
	
	public final Pair<String, ContainerTypeCode>  declarator() throws RecognitionException, TokenStreamException {
		Pair<String, ContainerTypeCode> pair = null;
		
		
		try {      // for error handling
			if ((LA(1)==IDENT) && (LA(2)==SEMI||LA(2)==COMMA)) {
				pair=simple_declarator();
			}
			else if ((LA(1)==IDENT) && (LA(2)==LBRACK)) {
				pair=complex_declarator();
			}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_50);
			} else {
			  throw ex;
			}
		}
		return pair;
	}
	
	public final Pair<String, ContainerTypeCode>  complex_declarator() throws RecognitionException, TokenStreamException {
		Pair<String, ContainerTypeCode> pair = null;
		
		
		try {      // for error handling
			pair=array_declarator();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_50);
			} else {
			  throw ex;
			}
		}
		return pair;
	}
	
	public final Pair<String, ContainerTypeCode>  array_declarator() throws RecognitionException, TokenStreamException {
		Pair<String, ContainerTypeCode> pair = null;
		
		
		String name = LT(1).getText(), size = null;
		ArrayTypeCode typecode = new ArrayTypeCode();
		
		
		try {      // for error handling
			match(IDENT);
			{
			int _cnt176=0;
			_loop176:
			do {
				if ((LA(1)==LBRACK)) {
					size=fixed_array_size();
					if ( inputState.guessing==0 ) {
						
							           typecode.addDimension(size);
							
					}
				}
				else {
					if ( _cnt176>=1 ) { break _loop176; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt176++;
			} while (true);
			}
			if ( inputState.guessing==0 ) {
				
					       pair = new Pair<String, ContainerTypeCode>(name, typecode);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_50);
			} else {
			  throw ex;
			}
		}
		return pair;
	}
	
	public final TypeCode  signed_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			if ((LA(1)==LITERAL_short)) {
				typecode=signed_short_int();
			}
			else if ((LA(1)==LITERAL_long) && (_tokenSet_35.member(LA(2)))) {
				typecode=signed_long_int();
			}
			else if ((LA(1)==LITERAL_long) && (LA(2)==LITERAL_long)) {
				typecode=signed_longlong_int();
			}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  unsigned_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		try {      // for error handling
			if ((LA(1)==LITERAL_unsigned) && (LA(2)==LITERAL_short)) {
				typecode=unsigned_short_int();
			}
			else if ((LA(1)==LITERAL_unsigned) && (LA(2)==LITERAL_long) && (_tokenSet_35.member(LA(3)))) {
				typecode=unsigned_long_int();
			}
			else if ((LA(1)==LITERAL_unsigned) && (LA(2)==LITERAL_long) && (LA(3)==LITERAL_long)) {
				typecode=unsigned_longlong_int();
			}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  signed_short_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_SHORT);
		
		
		try {      // for error handling
			match(LITERAL_short);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  signed_long_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_LONG);
		
		
		try {      // for error handling
			match(LITERAL_long);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  signed_longlong_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_LONGLONG);
		
		
		try {      // for error handling
			match(LITERAL_long);
			match(LITERAL_long);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  unsigned_short_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_USHORT);
		
		
		try {      // for error handling
			match(LITERAL_unsigned);
			match(LITERAL_short);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  unsigned_long_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_ULONG);
		
		
		try {      // for error handling
			match(LITERAL_unsigned);
			match(LITERAL_long);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final TypeCode  unsigned_longlong_int() throws RecognitionException, TokenStreamException {
		TypeCode typecode = new PrimitiveTypeCode(TypeCode.KIND_ULONGLONG);
		
		
		try {      // for error handling
			match(LITERAL_unsigned);
			match(LITERAL_long);
			match(LITERAL_long);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_35);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void member_list(
		StructTypeCode structTP
	) throws RecognitionException, TokenStreamException {
		
		
		Vector<Pair<String, TypeCode>> declvector = null;
		
		
		try {      // for error handling
			{
			int _cnt150=0;
			_loop150:
			do {
				if ((_tokenSet_13.member(LA(1)))) {
					declvector=member();
					if ( inputState.guessing==0 ) {
						
							           for(int count = 0; count < declvector.size(); ++count)
							               structTP.addMember(new StructMember(declvector.get(count).second(), declvector.get(count).first()));
							
					}
				}
				else {
					if ( _cnt150>=1 ) { break _loop150; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt150++;
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final Vector<Pair<String, TypeCode>>  member() throws RecognitionException, TokenStreamException {
		Vector<Pair<String, TypeCode>> newVector = new Vector<Pair<String, TypeCode>>();
		
		
		Vector<Pair<String, ContainerTypeCode>> declvector = null;
		TypeCode typecode = null;
		
		
		try {      // for error handling
			typecode=type_spec();
			declvector=declarators();
			match(SEMI);
			if ( inputState.guessing==0 ) {
				
					       for(int count = 0; count < declvector.size(); ++count)
					       {
					           if(declvector.get(count).second() != null)
					           {
					               // Array declaration
					               declvector.get(count).second().setContentTypeCode(typecode);
					               newVector.add(new Pair<String, TypeCode>(declvector.get(count).first(), declvector.get(count).second()));
					           }
					           else
					           {
					               // Simple declaration
					               newVector.add(new Pair<String, TypeCode>(declvector.get(count).first(), typecode));
					           }
					       }
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_51);
			} else {
			  throw ex;
			}
		}
		return newVector;
	}
	
	public final TypeCode  switch_type_spec() throws RecognitionException, TokenStreamException {
		TypeCode typecode = null;
		
		
		String literal = null;
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			{
				typecode=integer_type();
				break;
			}
			case LITERAL_char:
			{
				typecode=char_type();
				break;
			}
			case LITERAL_boolean:
			{
				typecode=boolean_type();
				break;
			}
			case LITERAL_enum:
			{
				enum_type();
				break;
			}
			case SCOPEOP:
			case IDENT:
			{
				literal=scoped_name();
				if ( inputState.guessing==0 ) {
					
					// Find typecode in the global map.
					typecode = ctx.getTypeCode(literal);
					
					if(typecode == null)
					System.out.println("ERROR: Cannot find the typecode for " + literal);
					
				}
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_27);
			} else {
			  throw ex;
			}
		}
		return typecode;
	}
	
	public final void switch_body(
		UnionTypeCode unionTP
	) throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			case_stmt_list(unionTP);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void case_stmt_list(
		UnionTypeCode unionTP
	) throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			int _cnt157=0;
			_loop157:
			do {
				if ((LA(1)==LITERAL_case||LA(1)==LITERAL_default)) {
					case_stmt(unionTP);
				}
				else {
					if ( _cnt157>=1 ) { break _loop157; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				
				_cnt157++;
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void case_stmt(
		UnionTypeCode unionTP
	) throws RecognitionException, TokenStreamException {
		
		
		Pair<String, TypeCode> element = null;
		String label = null;
		boolean defaul = false;
		UnionMember member = new UnionMember();
		
		
		try {      // for error handling
			{
			int _cnt160=0;
			_loop160:
			do {
				switch ( LA(1)) {
				case LITERAL_case:
				{
					match(LITERAL_case);
					label=const_exp();
					if ( inputState.guessing==0 ) {
						member.addLabel(label);
					}
					match(COLON);
					break;
				}
				case LITERAL_default:
				{
					match(LITERAL_default);
					if ( inputState.guessing==0 ) {
						defaul = true;
					}
					match(COLON);
					break;
				}
				default:
				{
					if ( _cnt160>=1 ) { break _loop160; } else {throw new NoViableAltException(LT(1), getFilename());}
				}
				}
				_cnt160++;
			} while (true);
			}
			element=element_spec();
			match(SEMI);
			if ( inputState.guessing==0 ) {
				
					       member.setTypecode(element.second());
					       member.setName(element.first());
					       int index = unionTP.addMember(member);
					       if(defaul) unionTP.setDefaultindex(index);
					
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_52);
			} else {
			  throw ex;
			}
		}
	}
	
	public final Pair<String, TypeCode>  element_spec() throws RecognitionException, TokenStreamException {
		Pair<String, TypeCode> newpair = null;
		
		
		Pair<String, ContainerTypeCode> decl = null;
		TypeCode typecode = null;
		
		
		try {      // for error handling
			typecode=type_spec();
			decl=declarator();
			if ( inputState.guessing==0 ) {
				
				if(decl.second() != null)
				{
				decl.second().setContentTypeCode(typecode);
				newpair = new Pair<String, TypeCode>(decl.first(), decl.second());
				}
				else
				{
				newpair = new Pair<String, TypeCode>(decl.first(), typecode);
				}
				
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
		return newpair;
	}
	
	public final void enumerator_list(
		EnumTypeCode enumTP
	) throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			enumerator(enumTP);
			{
			_loop165:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					enumerator(enumTP);
				}
				else {
					break _loop165;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void enumerator(
		EnumTypeCode enumTP
	) throws RecognitionException, TokenStreamException {
		
		
		String name = null;
		
		
		try {      // for error handling
			name=identifier();
			if ( inputState.guessing==0 ) {
				enumTP.addMember(new EnumMember(name));
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_53);
			} else {
			  throw ex;
			}
		}
	}
	
	public final String  opt_pos_int() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case COMMA:
			{
				match(COMMA);
				literal=positive_int_const();
				break;
			}
			case GT:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_54);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final String  fixed_array_size() throws RecognitionException, TokenStreamException {
		String literal = null;
		
		
		try {      // for error handling
			match(LBRACK);
			literal=positive_int_const();
			match(RBRACK);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_55);
			} else {
			  throw ex;
			}
		}
		return literal;
	}
	
	public final void readonly_attr_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_readonly);
			match(LITERAL_attribute);
			param_type_spec();
			readonly_attr_declarator();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void attr_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_attribute);
			param_type_spec();
			attr_declarator();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void opt_member_list() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			_loop182:
			do {
				if ((_tokenSet_13.member(LA(1)))) {
					member();
				}
				else {
					break _loop182;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void op_attribute() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_oneway);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_56);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void op_type_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_ValueBase:
			{
				param_type_spec();
				break;
			}
			case LITERAL_void:
			{
				match(LITERAL_void);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_31);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void parameter_dcls() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_in:
			case LITERAL_out:
			case LITERAL_inout:
			{
				param_dcl_list();
				break;
			}
			case RPAREN:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(RPAREN);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_57);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void context_expr() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_context);
			match(LPAREN);
			string_literal_list();
			match(RPAREN);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void param_dcl_list() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			param_dcl();
			{
			_loop193:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					param_dcl();
				}
				else {
					break _loop193;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_27);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void param_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_in:
			{
				match(LITERAL_in);
				break;
			}
			case LITERAL_out:
			{
				match(LITERAL_out);
				break;
			}
			case LITERAL_inout:
			{
				match(LITERAL_inout);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			param_type_spec();
			simple_declarator();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_29);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void string_literal_list() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			string_literal();
			{
			_loop200:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					string_literal();
				}
				else {
					break _loop200;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_27);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void imported_scope() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			{
				scoped_name();
				break;
			}
			case STRING_LITERAL:
			{
				string_literal();
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void readonly_attr_declarator() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			simple_declarator();
			{
			switch ( LA(1)) {
			case LITERAL_raises:
			{
				raises_expr();
				break;
			}
			case SEMI:
			case COMMA:
			{
				{
				_loop214:
				do {
					if ((LA(1)==COMMA)) {
						match(COMMA);
						simple_declarator();
					}
					else {
						break _loop214;
					}
					
				} while (true);
				}
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void attr_declarator() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			simple_declarator();
			{
			boolean synPredMatched219 = false;
			if (((LA(1)==SEMI||LA(1)==LITERAL_getraises||LA(1)==LITERAL_setraises) && (_tokenSet_58.member(LA(2))) && (_tokenSet_59.member(LA(3))) && (_tokenSet_60.member(LA(4))))) {
				int _m219 = mark();
				synPredMatched219 = true;
				inputState.guessing++;
				try {
					{
					switch ( LA(1)) {
					case LITERAL_getraises:
					{
						match(LITERAL_getraises);
						break;
					}
					case LITERAL_setraises:
					{
						match(LITERAL_setraises);
						break;
					}
					default:
					{
						throw new NoViableAltException(LT(1), getFilename());
					}
					}
					}
				}
				catch (RecognitionException pe) {
					synPredMatched219 = false;
				}
				rewind(_m219);
inputState.guessing--;
			}
			if ( synPredMatched219 ) {
				attr_raises_expr();
			}
			else if ((LA(1)==SEMI||LA(1)==COMMA) && (_tokenSet_61.member(LA(2))) && (_tokenSet_62.member(LA(3))) && (_tokenSet_63.member(LA(4)))) {
				{
				_loop221:
				do {
					if ((LA(1)==COMMA)) {
						match(COMMA);
						simple_declarator();
					}
					else {
						break _loop221;
					}
					
				} while (true);
				}
			}
			else {
				throw new NoViableAltException(LT(1), getFilename());
			}
			
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void attr_raises_expr() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_getraises:
			{
				get_excep_expr();
				break;
			}
			case SEMI:
			case LITERAL_setraises:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LITERAL_setraises:
			{
				set_excep_expr();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void get_excep_expr() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_getraises);
			exception_list();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_64);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void set_excep_expr() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_setraises);
			exception_list();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void exception_list() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LPAREN);
			scoped_name();
			{
			_loop229:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					scoped_name();
				}
				else {
					break _loop229;
				}
				
			} while (true);
			}
			match(RPAREN);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_64);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void component_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case COLON:
			{
				component_inheritance_spec();
				break;
			}
			case LCURLY:
			case LITERAL_supports:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LITERAL_supports:
			{
				supported_interface_spec();
				break;
			}
			case LCURLY:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(LCURLY);
			component_body();
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void component_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(COLON);
			scoped_name();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_25);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void supported_interface_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_supports);
			scoped_name();
			{
			_loop237:
			do {
				if ((LA(1)==COMMA)) {
					match(COMMA);
					scoped_name();
				}
				else {
					break _loop237;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_65);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void component_body() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			_loop241:
			do {
				if ((_tokenSet_66.member(LA(1)))) {
					component_export();
				}
				else {
					break _loop241;
				}
				
			} while (true);
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_15);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void component_export() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case LITERAL_provides:
			{
				provides_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_uses:
			{
				uses_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_emits:
			{
				emits_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_publishes:
			{
				publishes_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_consumes:
			{
				consumes_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_readonly:
			case LITERAL_attribute:
			{
				attr_dcl();
				match(SEMI);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_67);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void provides_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_provides);
			interface_type();
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void uses_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_uses);
			{
			switch ( LA(1)) {
			case LITERAL_multiple:
			{
				match(LITERAL_multiple);
				break;
			}
			case SCOPEOP:
			case IDENT:
			case LITERAL_Object:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			interface_type();
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void emits_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_emits);
			scoped_name();
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void publishes_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_publishes);
			scoped_name();
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void consumes_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_consumes);
			scoped_name();
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void interface_type() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			{
				scoped_name();
				break;
			}
			case LITERAL_Object:
			{
				match(LITERAL_Object);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_31);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void home_header() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_home);
			identifier();
			{
			switch ( LA(1)) {
			case COLON:
			{
				home_inheritance_spec();
				break;
			}
			case LITERAL_supports:
			case LITERAL_manages:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			{
			switch ( LA(1)) {
			case LITERAL_supports:
			{
				supported_interface_spec();
				break;
			}
			case LITERAL_manages:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(LITERAL_manages);
			scoped_name();
			{
			switch ( LA(1)) {
			case LITERAL_primarykey:
			{
				primary_key_spec();
				break;
			}
			case LCURLY:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void home_body() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LCURLY);
			{
			_loop261:
			do {
				if ((_tokenSet_68.member(LA(1)))) {
					home_export();
				}
				else {
					break _loop261;
				}
				
			} while (true);
			}
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void home_inheritance_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(COLON);
			scoped_name();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_69);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void primary_key_spec() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_primarykey);
			scoped_name();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_16);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void home_export() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			{
			switch ( LA(1)) {
			case SCOPEOP:
			case IDENT:
			case LITERAL_const:
			case LITERAL_typedef:
			case LITERAL_native:
			case LITERAL_float:
			case LITERAL_double:
			case LITERAL_long:
			case LITERAL_short:
			case LITERAL_unsigned:
			case LITERAL_char:
			case LITERAL_wchar:
			case LITERAL_boolean:
			case LITERAL_octet:
			case LITERAL_any:
			case LITERAL_Object:
			case LITERAL_struct:
			case LITERAL_union:
			case LITERAL_enum:
			case LITERAL_string:
			case LITERAL_wstring:
			case LITERAL_exception:
			case LITERAL_oneway:
			case LITERAL_void:
			case LITERAL_ValueBase:
			case LITERAL_typeid:
			case LITERAL_typeprefix:
			case LITERAL_readonly:
			case LITERAL_attribute:
			{
				export();
				break;
			}
			case LITERAL_factory:
			{
				factory_dcl();
				match(SEMI);
				break;
			}
			case LITERAL_finder:
			{
				finder_dcl();
				match(SEMI);
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_70);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void factory_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_factory);
			identifier();
			match(LPAREN);
			init_param_decls();
			match(RPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_raises:
			{
				raises_expr();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void finder_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_finder);
			identifier();
			match(LPAREN);
			init_param_decls();
			match(RPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_raises:
			{
				raises_expr();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_abs() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_abstract);
			event_header();
			{
			switch ( LA(1)) {
			case LCURLY:
			case COLON:
			case LITERAL_supports:
			{
				event_abs_dcl();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_custom() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_custom);
			event_header();
			event_elem_dcl();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			event_header();
			{
			switch ( LA(1)) {
			case LCURLY:
			case COLON:
			case LITERAL_supports:
			{
				event_elem_dcl();
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw new NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_header() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			match(LITERAL_eventtype);
			identifier();
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_71);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_abs_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			value_inheritance_spec();
			match(LCURLY);
			{
			_loop275:
			do {
				if ((_tokenSet_17.member(LA(1)))) {
					export();
				}
				else {
					break _loop275;
				}
				
			} while (true);
			}
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	public final void event_elem_dcl() throws RecognitionException, TokenStreamException {
		
		
		try {      // for error handling
			value_inheritance_spec();
			match(LCURLY);
			{
			_loop281:
			do {
				if ((_tokenSet_17.member(LA(1)))) {
					export();
				}
				else {
					break _loop281;
				}
				
			} while (true);
			}
			match(RCURLY);
		}
		catch (RecognitionException ex) {
			if (inputState.guessing==0) {
				reportError(ex);
				recover(ex,_tokenSet_10);
			} else {
			  throw ex;
			}
		}
	}
	
	
	public static final String[] _tokenNames = {
		"<0>",
		"EOF",
		"<2>",
		"NULL_TREE_LOOKAHEAD",
		";",
		"\"abstract\"",
		"\"local\"",
		"\"interface\"",
		"\"custom\"",
		"\"valuetype\"",
		"\"eventtype\"",
		"\"module\"",
		"{",
		"}",
		":",
		",",
		"::",
		"an identifer",
		"\"truncatable\"",
		"\"supports\"",
		"\"public\"",
		"\"private\"",
		"\"factory\"",
		"(",
		")",
		"\"in\"",
		"\"const\"",
		"=",
		"|",
		"^",
		"&",
		"<<",
		">>",
		"+",
		"-",
		"*",
		"/",
		"%",
		"~",
		"\"TRUE\"",
		"\"FALSE\"",
		"\"typedef\"",
		"\"native\"",
		"\"float\"",
		"\"double\"",
		"\"long\"",
		"\"short\"",
		"\"unsigned\"",
		"\"char\"",
		"\"wchar\"",
		"\"boolean\"",
		"\"octet\"",
		"\"any\"",
		"\"Object\"",
		"\"struct\"",
		"\"union\"",
		"\"switch\"",
		"\"case\"",
		"\"default\"",
		"\"enum\"",
		"\"sequence\"",
		"<",
		">",
		"\"string\"",
		"\"wstring\"",
		"[",
		"]",
		"\"exception\"",
		"\"oneway\"",
		"\"void\"",
		"\"out\"",
		"\"inout\"",
		"\"raises\"",
		"\"context\"",
		"\"fixed\"",
		"\"ValueBase\"",
		"\"import\"",
		"\"typeid\"",
		"\"typeprefix\"",
		"\"readonly\"",
		"\"attribute\"",
		"\"getraises\"",
		"\"setraises\"",
		"\"component\"",
		"\"provides\"",
		"\"uses\"",
		"\"multiple\"",
		"\"emits\"",
		"\"publishes\"",
		"\"consumes\"",
		"\"home\"",
		"\"manages\"",
		"\"primarykey\"",
		"\"finder\"",
		"an integer value",
		"an octal value",
		"a hexadecimal value value",
		"a string literal",
		"a wide string literal",
		"a character literal",
		"a wide character literal",
		"FIXED",
		"a floating point value",
		"?",
		".",
		"!",
		"white space",
		"a preprocessor directive",
		"a comment",
		"a comment",
		"an escape sequence",
		"an escaped character value",
		"a digit",
		"a non-zero digit",
		"an octal digit",
		"a hexadecimal digit",
		"an escaped identifer"
	};
	
	private static final long[] mk_tokenSet_0() {
		long[] data = { 630510544968749024L, 67657736L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_0 = new BitSet(mk_tokenSet_0());
	private static final long[] mk_tokenSet_1() {
		long[] data = { 2L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_1 = new BitSet(mk_tokenSet_1());
	private static final long[] mk_tokenSet_2() {
		long[] data = { 630510544968749024L, 67661832L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_2 = new BitSet(mk_tokenSet_2());
	private static final long[] mk_tokenSet_3() {
		long[] data = { 151568L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_3 = new BitSet(mk_tokenSet_3());
	private static final long[] mk_tokenSet_4() {
		long[] data = { -8574855889469341710L, 67758137L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_4 = new BitSet(mk_tokenSet_4());
	private static final long[] mk_tokenSet_5() {
		long[] data = { -7421940981998858224L, 3073L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_5 = new BitSet(mk_tokenSet_5());
	private static final long[] mk_tokenSet_6() {
		long[] data = { -6269012880247521294L, 67758137L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_6 = new BitSet(mk_tokenSet_6());
	private static final long[] mk_tokenSet_7() {
		long[] data = { 675856L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_7 = new BitSet(mk_tokenSet_7());
	private static final long[] mk_tokenSet_8() {
		long[] data = { -8574855889468555278L, 67758137L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_8 = new BitSet(mk_tokenSet_8());
	private static final long[] mk_tokenSet_9() {
		long[] data = { 630510544968757218L, 67657736L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_9 = new BitSet(mk_tokenSet_9());
	private static final long[] mk_tokenSet_10() {
		long[] data = { 16L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_10 = new BitSet(mk_tokenSet_10());
	private static final long[] mk_tokenSet_11() {
		long[] data = { -8574855889469345792L, 124985L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_11 = new BitSet(mk_tokenSet_11());
	private static final long[] mk_tokenSet_12() {
		long[] data = { 630510544968757234L, 67657736L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_12 = new BitSet(mk_tokenSet_12());
	private static final long[] mk_tokenSet_13() {
		long[] data = { -7421940981999403008L, 3073L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_13 = new BitSet(mk_tokenSet_13());
	private static final long[] mk_tokenSet_14() {
		long[] data = { -2738197094764646384L, 8992984325L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_14 = new BitSet(mk_tokenSet_14());
	private static final long[] mk_tokenSet_15() {
		long[] data = { 8192L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_15 = new BitSet(mk_tokenSet_15());
	private static final long[] mk_tokenSet_16() {
		long[] data = { 4096L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_16 = new BitSet(mk_tokenSet_16());
	private static final long[] mk_tokenSet_17() {
		long[] data = { -8574855889469374464L, 124985L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_17 = new BitSet(mk_tokenSet_17());
	private static final long[] mk_tokenSet_18() {
		long[] data = { -8574855889462026240L, 536995897L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_18 = new BitSet(mk_tokenSet_18());
	private static final long[] mk_tokenSet_19() {
		long[] data = { 16781312L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_19 = new BitSet(mk_tokenSet_19());
	private static final long[] mk_tokenSet_20() {
		long[] data = { 36864L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_20 = new BitSet(mk_tokenSet_20());
	private static final long[] mk_tokenSet_21() {
		long[] data = { 4611686293054345232L, 8992587780L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_21 = new BitSet(mk_tokenSet_21());
	private static final long[] mk_tokenSet_22() {
		long[] data = { -8574855889462034432L, 124985L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_22 = new BitSet(mk_tokenSet_22());
	private static final long[] mk_tokenSet_23() {
		long[] data = { 131088L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_23 = new BitSet(mk_tokenSet_23());
	private static final long[] mk_tokenSet_24() {
		long[] data = { -8574855889462026240L, 124985L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_24 = new BitSet(mk_tokenSet_24());
	private static final long[] mk_tokenSet_25() {
		long[] data = { 528384L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_25 = new BitSet(mk_tokenSet_25());
	private static final long[] mk_tokenSet_26() {
		long[] data = { 561152L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_26 = new BitSet(mk_tokenSet_26());
	private static final long[] mk_tokenSet_27() {
		long[] data = { 16777216L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_27 = new BitSet(mk_tokenSet_27());
	private static final long[] mk_tokenSet_28() {
		long[] data = { 16L, 512L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_28 = new BitSet(mk_tokenSet_28());
	private static final long[] mk_tokenSet_29() {
		long[] data = { 16809984L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_29 = new BitSet(mk_tokenSet_29());
	private static final long[] mk_tokenSet_30() {
		long[] data = { -9205366434438119424L, 2049L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_30 = new BitSet(mk_tokenSet_30());
	private static final long[] mk_tokenSet_31() {
		long[] data = { 131072L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_31 = new BitSet(mk_tokenSet_31());
	private static final long[] mk_tokenSet_32() {
		long[] data = { 16810000L, 393472L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_32 = new BitSet(mk_tokenSet_32());
	private static final long[] mk_tokenSet_33() {
		long[] data = { 1950057955328L, 548682072064L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_33 = new BitSet(mk_tokenSet_33());
	private static final long[] mk_tokenSet_34() {
		long[] data = { 4611686018444214288L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_34 = new BitSet(mk_tokenSet_34());
	private static final long[] mk_tokenSet_35() {
		long[] data = { 4611686018444328976L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_35 = new BitSet(mk_tokenSet_35());
	private static final long[] mk_tokenSet_36() {
		long[] data = { 4611686018427551760L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_36 = new BitSet(mk_tokenSet_36());
	private static final long[] mk_tokenSet_37() {
		long[] data = { 4611686018712649744L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_37 = new BitSet(mk_tokenSet_37());
	private static final long[] mk_tokenSet_38() {
		long[] data = { 4611686019249520656L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_38 = new BitSet(mk_tokenSet_38());
	private static final long[] mk_tokenSet_39() {
		long[] data = { 4611686020323262480L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_39 = new BitSet(mk_tokenSet_39());
	private static final long[] mk_tokenSet_40() {
		long[] data = { 4611686026765713424L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_40 = new BitSet(mk_tokenSet_40());
	private static final long[] mk_tokenSet_41() {
		long[] data = { 4611686052535517200L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_41 = new BitSet(mk_tokenSet_41());
	private static final long[] mk_tokenSet_42() {
		long[] data = { 4611686293053685776L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_42 = new BitSet(mk_tokenSet_42());
	private static final long[] mk_tokenSet_43() {
		long[] data = { 4611686018427420672L, 4L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_43 = new BitSet(mk_tokenSet_43());
	private static final long[] mk_tokenSet_44() {
		long[] data = { 16908304L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_44 = new BitSet(mk_tokenSet_44());
	private static final long[] mk_tokenSet_45() {
		long[] data = { 4611703610613596176L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_45 = new BitSet(mk_tokenSet_45());
	private static final long[] mk_tokenSet_46() {
		long[] data = { 5242198513336692722L, 548750123274L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_46 = new BitSet(mk_tokenSet_46());
	private static final long[] mk_tokenSet_47() {
		long[] data = { -2377900603386646542L, 549348962299L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_47 = new BitSet(mk_tokenSet_47());
	private static final long[] mk_tokenSet_48() {
		long[] data = { 4611791571543818256L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_48 = new BitSet(mk_tokenSet_48());
	private static final long[] mk_tokenSet_49() {
		long[] data = { 5242233697708781554L, 548750123274L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_49 = new BitSet(mk_tokenSet_49());
	private static final long[] mk_tokenSet_50() {
		long[] data = { 32784L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_50 = new BitSet(mk_tokenSet_50());
	private static final long[] mk_tokenSet_51() {
		long[] data = { -7421940981999394816L, 3073L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_51 = new BitSet(mk_tokenSet_51());
	private static final long[] mk_tokenSet_52() {
		long[] data = { 432345564227575808L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_52 = new BitSet(mk_tokenSet_52());
	private static final long[] mk_tokenSet_53() {
		long[] data = { 40960L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_53 = new BitSet(mk_tokenSet_53());
	private static final long[] mk_tokenSet_54() {
		long[] data = { 4611686018427387904L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_54 = new BitSet(mk_tokenSet_54());
	private static final long[] mk_tokenSet_55() {
		long[] data = { 32784L, 2L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_55 = new BitSet(mk_tokenSet_55());
	private static final long[] mk_tokenSet_56() {
		long[] data = { -9205366434438119424L, 2081L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_56 = new BitSet(mk_tokenSet_56());
	private static final long[] mk_tokenSet_57() {
		long[] data = { 16L, 768L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_57 = new BitSet(mk_tokenSet_57());
	private static final long[] mk_tokenSet_58() {
		long[] data = { -8574855889453637632L, 598861881L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_58 = new BitSet(mk_tokenSet_58());
	private static final long[] mk_tokenSet_59() {
		long[] data = { -5116097972785709040L, 4262945L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_59 = new BitSet(mk_tokenSet_59());
	private static final long[] mk_tokenSet_60() {
		long[] data = { -6196953336277385230L, 548749731849L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_60 = new BitSet(mk_tokenSet_60());
	private static final long[] mk_tokenSet_61() {
		long[] data = { -8574855889462026240L, 598861881L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_61 = new BitSet(mk_tokenSet_61());
	private static final long[] mk_tokenSet_62() {
		long[] data = { -5116097972785676272L, 4262945L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_62 = new BitSet(mk_tokenSet_62());
	private static final long[] mk_tokenSet_63() {
		long[] data = { -6196953336286855182L, 549348567097L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_63 = new BitSet(mk_tokenSet_63());
	private static final long[] mk_tokenSet_64() {
		long[] data = { 16L, 262144L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_64 = new BitSet(mk_tokenSet_64());
	private static final long[] mk_tokenSet_65() {
		long[] data = { 4096L, 134217728L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_65 = new BitSet(mk_tokenSet_65());
	private static final long[] mk_tokenSet_66() {
		long[] data = { 0L, 61964288L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_66 = new BitSet(mk_tokenSet_66());
	private static final long[] mk_tokenSet_67() {
		long[] data = { 8192L, 61964288L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_67 = new BitSet(mk_tokenSet_67());
	private static final long[] mk_tokenSet_68() {
		long[] data = { -8574855889465180160L, 536995897L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_68 = new BitSet(mk_tokenSet_68());
	private static final long[] mk_tokenSet_69() {
		long[] data = { 524288L, 134217728L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_69 = new BitSet(mk_tokenSet_69());
	private static final long[] mk_tokenSet_70() {
		long[] data = { -8574855889465171968L, 536995897L, 0L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_70 = new BitSet(mk_tokenSet_70());
	private static final long[] mk_tokenSet_71() {
		long[] data = { 544784L, 0L};
		return data;
	}
	public static final BitSet _tokenSet_71 = new BitSet(mk_tokenSet_71());
	
	}
