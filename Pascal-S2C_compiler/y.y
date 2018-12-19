%{
    #include <cmath>
    #include <string>
	#include <cstring>
    #include <iostream>
    #include <vector>
	#include <stack>
	#include <map>
	#include <unordered_set>
	#include <fstream>
	#include <sstream>
    #include "dec.h"
	extern FILE* yyin;
	extern int yylineno;
    // std::string varout;
    int       yylex(void);
    void      yyerror(char const *);
	std::stack<symtabele> 	symtab;					//主符号表
	std::stack<symtabeleP> 	indextab;				//索引表
	std::map<std::string,typeAttri> customtypetab;	//全局自定义类型表
	std::map<std::string,funInfo> funtab;			//全局函数表
	std::map<std::string,paraInfo> protab;			//全剧过程表
	std::ofstream out;
    std::string record2struct(std::pair<std::string, typeAttri> recordin);
   
%}

%union{
	terminalSAttriP 		terattrip;
	idlistAttriP			idlistattrip;
	typeAttrip				typeattrip;
	periodAttrip			periodattrip;
	periodsAttrip			periodsattrip;
	type_declarationAttrip 	type_declarationattrip;
	var_declarationAttrip 	var_declarationattrip;
	record_bodyAttrip		record_bodyattrip;
	id_varpartAttrip		id_varpartattrip;
	id_varpartsAttrip		id_varpartsattrip;
	expression_listAttrip	expression_listattrip;

	paraInfop				parainfop;		
	double					numer_val;
	TYPEKIND				typekind;
	strp					strAttri;
    int                     IINT;
    //std::string                  STRING;
}

/*标识符*/
%token  <terattrip> ID       /*-----[a-zA-Z][a-zA-Z0-9]*----*/

/*常数*/
%token  <terattrip> NUM      /*-------{DIGIT}+(\.{DIGIT}+)?(E[+\-]?{DIGIT}*)?-----*/

 /*关系运算*/
%token  <terattrip> RELOP    /*----'<'|'>'|'<>'|'<='|'>='---------*/      	   

/*关键字*/
%token TYPE
%token PROGRAM
%token PROCEDURE
%token FUNCTION
%token IF
%token ELSE
%token THEN
%token CONST
%token INTEGER
%token BEGINpas
%token END
%token VAR
%token WHILE
%token REAL
%token NOT
%token TO
%token UNTIL
%token OF
%token CHAR
%token FOR
%token BOOLEAN
%token CASE
%token DOWNTO
%token ARRAY
%token RECORD
%token REPEAT
%token OR
%token MOD
%token DIV
%token AND
%token DO

/*标点符号*/
%token COMMA              /*逗号----','*/
%token SEMICOLON          /*分号----';'*/
%token DOT                /*点------'.'*/
%token COLON              /*冒号----':'*/
%token LEFTBRACKETS  	RIGHTBRACKETS             	/*左右圆括号*/
%token LEFTSQUBRACKETS 	RIGHTSQUBRACKETS        	/*左右方括号*/
/*运算符号*/
%token ASSIGNOP/*赋值----':='*/
%token EQUSIGN            /*等于号---'='*/
%token PLUS               /*加号----'+'*/
%token MINUS              /*减号----'-'*/
%token DIVISION           /*除号----'/'*/
%token MULTIPLY           /*乘号----'*'*/



%nonassoc LOWER_THAN_ELSE /*为了解决if-else的else移进规约冲突，这是个伪token，不用词法分析返回*/
%nonassoc ELSE            /*为了解决if-else的else移进规约冲突*/


/*------------以下为非终结符号的属性声明-----------------*/
%type <idlistattrip> 			idlist
%type <numer_val> 				const_value
%type <typekind>				standard_type
%type <typeattrip>				type
%type <periodattrip>			period
%type <periodsattrip>			periods
%type <type_declarationattrip> 	type_declaration
%type <var_declarationattrip>	var_declaration
%type <record_bodyattrip>		record_body
%type <parainfop>				parameter
%type <parainfop>				parameter_list
%type <parainfop>				formal_parameter
%type <id_varpartattrip>		id_varpart
%type <id_varpartsattrip>		id_varparts
%type <expression_listattrip>	expression_list
%type <strAttri>				compound_statement
%type <strAttri> 				statement_list
%type <strAttri> 				statement
%type <strAttri> 				expression
%type <strAttri> 				simple_expression
%type <strAttri> 				term
%type <strAttri> 				factor
%type <strAttri> 				variable
/*---------代码生成中的非终结符属性定义---------*/
//%type <>                  const_declaration
//%type <type_declarationattrip>                  type_declarations
%type <strAttri>                procedure_call
%type <IINT>                updown
%%

//cgdone
programstruct:                  program_head  program_body DOT
								{ 
									out.close();
								}
;

//cgdone
program_head:                   PROGRAM ID LEFTBRACKETS idlist RIGHTBRACKETS SEMICOLON
                                {
									//注：input和output暂时没有处理
                                	symtabele * tabelep = new symtabele();
                                	tabelep->name = $2->id_name;
                                	tabelep->kind = PROGRAMt;
                                	tabelep->constornot = false;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
                                	delete(tabelep);							//这delete的顺序不能随意改变
                                  	tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									/*-----以上为语义分析部分，已完成--------*/

									out << "#include <stdlib.h>\n";
									out << "#include <stdio.h>\n";
                                    out << "\n";
                                    out << "#define bool int\n";
                                    out << "#define true 1\n";
                                    out << "#define false 0\n";
                                    out << "\n";

								
                                    delete($2);
									delete($4);
                                }
;

//cgdone
program_body:                   const_declarations type_declarations var_declarations subprogram_declarations compound_statement
								{
									out << "int main()\n";
									out << "{\n";
									out << *($5);
									out << "\nreturn 0;\n}";
								}
;

//cgdone
idlist:                         idlist COMMA ID
                                { 
									$$ = new(idlistAttri);
                                  	for( auto & i: $1->ids ){
                                	 	$$->ids.push_back(i);
                                  	}
                                    $$->ids.push_back($3->id_name);
                                    //out << $3->id_name;

									/*-----以上为语义分析部分，已完成--------*/

									delete($1);
									delete($3);
                                }
                               | ID 
                                {
									$$ = new(idlistAttri);
									$$->ids.push_back($1->id_name);

									/*-----以上为语义分析部分，已完成--------*/
                                    //out << $1->id_name;

									delete($1);
                                }
;

//cgdone
const_declarations:             CONST const_declaration SEMICOLON
                                | empty

;
//cgdone
const_declaration:              const_declaration SEMICOLON ID EQUSIGN const_value
                                {
                                  	symtabele * tabelep = new symtabele();
                                	tabelep->name = $3->id_name;
                                	tabelep->kind = REALt;
                                	tabelep->constornot = true;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
									/*-----以上为语义分析部分，已完成--------*/
									 out << "const double " << $3->id_name << "=" << $5 << ";\n";
                                    /*------代码生成部分------*/
                                    delete(tabelep);
                                }
                                | ID EQUSIGN const_value
                                {
                                  	symtabele * tabelep = new symtabele();
                                	tabelep->name = $1->id_name;
                                	tabelep->kind = REALt;
                                	tabelep->constornot = true;
                                	tabelep->tinfop = NULL;                                  
                                	symtab.push(*tabelep);
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "const double " << $1->id_name << "=" << $3 << ";\n";
                                    /*------代码生成部分------*/


                                	delete(tabelep);
                                }
;
const_value:                    PLUS ID     
								{
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == $2->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<$2->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "+";
                                    //out << $2->id_name;
                                    /*------代码生成部分----有错误--*/
								}
                                | MINUS ID
								{
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == $2->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<$2->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "-";
                                    //out << $2->id_name;
                                    /*------代码生成部分------*/
                                    
								}
                                | ID        
								{
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == $1->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<$1->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    
                                   // out << $1->id_name;
                                    /*------代码生成部分------*/
                                    
								}
                                | PLUS NUM	
								{ 
									$$ = $2->val; 	
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "+";
                                    //out << $2->val;
                                    /*------代码生成部分------*/
                                    
								}
                                | MINUS NUM 
								{ 
									$$ = -$2->val; 
									/*-----以上为语义分析部分，完成--------*/
                                    //out << "-";
                                    //out << $2->val;
                                    /*------代码生成部分------*/
                                    
								}
                                | NUM 		
								{ 
									$$ = $1->val; 	
									/*-----以上为语义分析部分，完成--------*/
                                    //out << $1->val;
                                    /*------代码生成部分------*/
                                    
								}
;



type_declarations:              TYPE type_declaration SEMICOLON
								| empty
;
type_declaration:              type_declaration SEMICOLON ID EQUSIGN type
								{
									customtypetab.insert(std::pair<std::string,typeAttri>($3->id_name,*($5)));
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "typedef ";
                                    
                                    if( $5->kind == RECORDt){
                                        out << record2struct(std::pair<std::string,typeAttri>($3->id_name,*($5))) << "\n";}
                                    else if($5->kind==INTEGERt)
                                    {
                                        out << "int " << $3->id_name << ";" << "\n";
                                    }
                                    else if($5->kind==REALt)
                                    {
                                        out << "double " << $3->id_name << ";" << "\n";
                                    }
                                    else if($5->kind==CHARt)
                                    {
                                        out << "char " << $3->id_name << ";" << "\n";
                                    }
                                    else if($5->kind==BOOLEANt)
                                    {
                                        out << "bool " << $3->id_name << ";" << "\n";
                                    }
                                    else if($5->kind==ARRAYt)
                                    {
                                        switch($5->arraytp->kind){
                                            case INTEGER:
                                            out << "int ";
                                            break;
                                            case REALt:
                                            out << "double ";
                                            break;
                                            case CHARt:
                                            out << "char ";
                                            break;
                                            case BOOLEANt:
                                            out << "bool ";
                                            break;
                                        }
                                        out << $3->id_name << "[" << $5->periods.size() << "]" <<";" << "\n";
                                        

                                    }



                                        //<< $5->kind << ";" << "\n";
                                    
                            
                                   /*-------代码生成部分-------*/
								}
								
                               | ID EQUSIGN type
								{
									customtypetab.insert(std::pair<std::string,typeAttri>($1->id_name,*($3)));
									/*-----以上为语义分析部分，已完成--------*/
                                    out << "typedef ";
                                    if( $3->kind == RECORDt){
                                        out << record2struct(std::pair<std::string,typeAttri>($1->id_name,*($3))) << "\n";}
                                    else if($3->kind==INTEGERt)
                                    {
                                        out << "int " << $1->id_name << ";" << "\n";
                                    }
                                    else if($3->kind==REALt)
                                    {
                                        out << "double " << $1->id_name << ";" << "\n";
                                    }
                                    else if($3->kind==CHARt)
                                    {
                                        out << "char " << $1->id_name << ";" << "\n";
                                    }
                                    else if($3->kind==BOOLEANt)
                                    {
                                        out << "bool " << $1->id_name << ";" << "\n";
                                    }
                                    else if($3->kind==ARRAYt)
                                    {
                                        switch($3->arraytp->kind){
                                            case INTEGER:
                                            out << "int ";
                                            break;
                                            case REALt:
                                            out << "double ";
                                            break;
                                            case CHARt:
                                            out << "char ";
                                            break;
                                            case BOOLEANt:
                                            out << "bool ";
                                            break;
                                        }
                                        out << $1->id_name << "[" << $3->periods.size() << "]" << "\n";
                                    }
                                    

                                    
                                    
                                
                                    /*-------代码生成部分-------*/
								}
;

type:                           standard_type
								{
									$$ = new(typeAttri);
									$$->kind = $1;
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*code generation*/
                            }
                            | RECORD record_body  END
								{
									$$ = new(typeAttri);
									$$->kind = RECORDt;
									$$->records = *$2;
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*-------code generation-------*/
								}
                                | ARRAY LEFTSQUBRACKETS periods RIGHTSQUBRACKETS OF type
								{
									$$ = new(typeAttri);
									$$->kind = ARRAYt;
									$$->periods = *$3;
									$$->arraytp = $6;
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    /*-------code generation-------*/
								}
;

standard_type:         INTEGER 	{ $$ = INTEGERt	}
| REAL 		{ $$ = REALt	}
| BOOLEAN 	{ $$ = BOOLEANt }
| CHAR		{ $$ = CHARt	}
;

record_body:                   var_declaration
								{
									$$ = new(record_bodyAttri);
									//*($$) = *($1);
									*($$) = $1->var_declarationAttrimap;
									/*-----以上为语义分析部分，已完成--------*/
                                    
                                    //out << "struct{" << "\n";
                                    //out << "typedef" << " ";
                                    
																	}
                                | empty
								{
									$$ = new(record_bodyAttri);
									/*-----以上为语义分析部分，已完成--------*/
									
								}
;

periods:                        periods COMMA period
								{
									$$ = new(periodsAttri);
									for( auto &i : *($1) ){
										$$->push_back(i);
									}
									for( auto &i : *($3) ){
										$$->push_back(i);
									}
									/*-----以上为语义分析部分，已完成--------*/
									
								}
                                | period
								{
									$$ = new(periodsAttri);
									for( auto &i : *($1) ){
                                    $$->push_back(i);
									}
									/*-----以上为语义分析部分，已完成--------*/
									
								}
;

period:                         const_value DOT DOT const_value
								{
									$$ = new(periodAttri);
									$$->push_back($1);
									$$->push_back($4);
									/*-----以上为语义分析部分，已完成--------*/
									
								}
;



var_declarations:               VAR var_declaration SEMICOLON
								{
									for( auto & i : $2->var_declarationAttrimap ){
										symtabele * tabelep = new symtabele();
                                    	tabelep->name = i.first;
                                		tabelep->kind = i.second->kind;
                                		tabelep->constornot = false;
                                		tabelep->tinfop = i.second;                                  
                                		symtab.push(*tabelep);
										
                                		delete(tabelep);
                                        
									}
									/*-----以上为语义分析部分，已完成--------*/
									out << $2->varout;
								}
                                | empty
;


var_declaration:                var_declaration SEMICOLON idlist COLON type
								{
									$$ = new(var_declarationAttri);
									for( auto &i : $1->var_declarationAttrimap ){
										$$->var_declarationAttrimap.insert(i);
									}
									for( auto &i : $3->ids ){
										$$->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,$5));
									}
									/*-----以上为语义分析部分，已完成--------*/

									$$->varout.append($1->varout);
									$$->varout.append("\n");

									switch( $5->kind ){
										case INTEGERt:
											{
											$$->varout.append("int ");
											for( auto &i : $3->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case REALt:
											{
											$$->varout.append("double ");
											for( auto &i : $3->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case BOOLEANt:
											{
											$$->varout.append("bool ");
											for( auto &i : $3->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case CHARt:
											{
											$$->varout.append("char ");
											for( auto &i : $3->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										
										case RECORDt:
											{
                                                
                                                $$->varout.append(record2struct(std::pair<std::string,typeAttri>($3->ids[0],*($5))) );//???
                                                $$->varout.append("\n");
                                            
											}
										break;
										case ARRAYt:
                                        {
                                            switch($5->arraytp->kind){
                                                case INTEGERt:
                                                $$->varout.append("int ");
                                                break;
                                                case REALt:
                                                $$->varout.append("double ");
                                                break;
                                                case CHARt:
                                                $$->varout.append("char ");
                                                break;
                                                case BOOLEANt:
                                                $$->varout.append("bool");
                                                break;
                                            }
                                            for( auto &i : $3->ids){
                                                $$->varout.append(i);
                                                $$->varout.append("[");
                                                //vector 容量表示
                                                int a1 = (int)($5->periods)[1];
                                                std::stringstream ss11;
												a1++;
                                                ss11<<a1;
                                                std::string str1 = ss11.str();
                                                $$->varout.append(str1);
                                                $$->varout.append("]");
                                                $$->varout.append(",");//结构体表示？？？
                                            }
                                            auto tempiter = $$->varout.end();
                                            tempiter--;
                                            $$->varout.erase(tempiter);
                                            $$->varout.append(";");
                                            
                                        }
										break;
									}
                                    $$->varout.append("\n");


                                    //代码生成ddddd
								}
								|
								var_declaration SEMICOLON idlist COLON ID
								{
									$$ = new(var_declarationAttri);
									for( auto &i : $1->var_declarationAttrimap ){
										$$->var_declarationAttrimap.insert(i);
									}
									//查全局的自定义类型表，把自定义类型的类型树
									/*-----以上为语义分析部分，完成--------*/
									auto iter = customtypetab.find($5->id_name);
									if( iter != customtypetab.end() ){
										
										for( auto &i : $3->ids ){
											$$->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,&((*iter).second)) );
										}
									}else{
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The type "<< '\'' <<$5->id_name << '\'' <<" has not been decleared yet.\n";
									}
                                
									/*-----以上为语义分析部分，完成--------*/
									
									$$->varout.append($1->varout);
									$$->varout.append("\n");

									$$->varout.append($5->id_name);

									$$->varout.append(" ");
									for( auto &i : $3->ids ){
										$$->varout.append(i);
										$$->varout.append(",");
									}
									auto tempiter = $$->varout.end();
									tempiter--;
									$$->varout.erase(tempiter);

									


                                    $$->varout.append(";\n\n");
                                }
                                |idlist COLON type
								{
									$$ = new(var_declarationAttri);
									for( auto &i : $1->ids ){
										$$->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,$3));
									}
									/*-----以上为语义分析部分，已完成--------*/
                                    
						

									switch( $3->kind ){
										case INTEGERt:
											{
											$$->varout.append("int ");
											for( auto &i : $1->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case REALt:
											{
											$$->varout.append("double ");
											for( auto &i : $1->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case BOOLEANt:
											{
											$$->varout.append("bool ");
											for( auto &i : $1->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										case CHARt:
											{
											$$->varout.append("char ");
											for( auto &i : $1->ids ){
												$$->varout.append(i);
												$$->varout.append(",");
											}
											auto tempiter = $$->varout.end();
											tempiter--;
											$$->varout.erase(tempiter);
											$$->varout.append(";");
											break;
											}
										
										case RECORDt:
											{
                                                $$->varout.append(record2struct(std::pair<std::string,typeAttri>($1->ids[0],*($3))) );//???
                                                $$->varout.append("\n");
                                            }
										break;
										case ARRAYt:
                                        {
                                            switch($3->arraytp->kind){
                                                case INTEGERt:
                                                $$->varout.append("int ");
                                                break;
                                                case REALt:
                                                $$->varout.append("double ");
                                                break;
                                                case CHARt:
                                                $$->varout.append("char ");
                                                break;
                                                case BOOLEANt:
                                                $$->varout.append("bool");
                                                break;
                                            }
                                            for( auto &i : $1->ids){
                                                $$->varout.append(i);
                                                $$->varout.append("[");
                                                //vector 容量表示
                                                int a2 = (int)($3->periods)[1];
												a2++;
                                                std::stringstream ss12;
                                                ss12<<a2;
                                                std::string str2 = ss12.str();
                                                $$->varout.append(str2);
                                                $$->varout.append("]");
                                                $$->varout.append(",");//结构体表示？？？
                                            }
                                            auto tempiter = $$->varout.end();
                                            tempiter--;
                                            $$->varout.erase(tempiter);
                                            $$->varout.append(";");
                                        }
										break;
									}
                                    $$->varout.append("\n");

                                 }







                

								| idlist COLON ID
								{
									$$ = new(var_declarationAttri);
									//查全局的自定义类型表，把自定义类型的类型树
									
									auto iter = customtypetab.find($3->id_name);
									if( iter != customtypetab.end() ){
										
										for( auto &i : $1->ids ){
											$$->var_declarationAttrimap.insert(std::pair<std::string, typeAttrip>(i,&((*iter).second)) );
										}
									}else{
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The type "<< '\'' <<$3->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    
									$$->varout.append($3->id_name);

									$$->varout.append(" ");
									for( auto &i : $1->ids ){
										$$->varout.append(i);
										$$->varout.append(",");
									}
									auto tempiter = $$->varout.end();
									tempiter--;
									$$->varout.erase(tempiter);

									


                                    $$->varout.append(";\n\n");



                                    //代码生成
								}
                                
;






subprogram_declarations:        subprogram_declarations subprogram SEMICOLON
								{
									//释放块
									auto pointer = indextab.top();
									indextab.pop();
									while( &(symtab.top()) != pointer){
										symtab.pop();
                                        
									}
									symtab.pop();
									/*-----以上为语义分析部分，完成--------*/
								}
                                | empty
;

//cgdone
subprogram:                     subprogram_head  subprogram_body
;

//cgdone
subprogram_head:                PROCEDURE ID formal_parameter SEMICOLON
								{
									symtabele * tabelep = new symtabele();
                                	tabelep->name = $2->id_name;
                                	tabelep->kind = PROCEDUREt;
                                	tabelep->constornot = false;
									tabelep->dimension = $3->size();
                                	tabelep->tinfop = NULL;
									tabelep->parainfop  =  $3;                        
                                	symtab.push(*tabelep);
									tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									protab.insert(std::pair<std::string,paraInfo>($2->id_name,*$3));
									/*-----以上为语义分析部分，完成--------*/

									out << "void ";
									out << $2->id_name;
									out << "(";
									std::string tempstr;
									for( auto &i : *($3) ){
										switch(i.second){
											case REALt:
												tempstr.append("double ");
												break;
											case CHARt:
												tempstr.append("char ");
												break;
											case INTEGERt:
												tempstr.append("int ");
												break;
											case BOOLEANt:
												tempstr.append("bool ");
												break;
										}
										tempstr.append(i.first);
										tempstr.append(",");
									}
									auto eiter = tempstr.end();
									eiter--;
									tempstr.erase(eiter);
									out << tempstr;
									out << ")\n{\n";

								}
                                | FUNCTION ID formal_parameter COLON standard_type SEMICOLON
								{
									symtabele * tabelep = new symtabele();
                                	tabelep->name = $2->id_name;
                                	tabelep->kind = FUNCTIONt;
                                	tabelep->constornot = false;
									tabelep->dimension = $3->size();
                                	tabelep->tinfop = NULL;
									tabelep->parainfop  =  $3;
									tabelep->rekind = $5;                        
                                	symtab.push(*tabelep);
									tabelep = &symtab.top();
                                  	indextab.push(tabelep);
									

									funInfop finfop = new(funInfo);
									finfop->returntype = $5;
									finfop->parainfo = *$3;
									funtab.insert(std::pair<std::string,funInfo>($2->id_name,*finfop));
									delete finfop;
									/*-----以上为语义分析部分，完成--------*/


									switch($5){
										case REALt:
										out << "double ";
										break;
										case CHARt:
										out << "char ";
										break;
										case INTEGERt:
										out << "int ";
										break;
										case BOOLEANt:
										out << "bool ";
										break;
									}
									out << $2->id_name;
									out << "(";
									std::string tempstr;
									for( auto &i : *($3) ){
										switch(i.second){
											case REALt:
												tempstr.append("double ");
												break;
											case CHARt:
												tempstr.append("char ");
												break;
											case INTEGERt:
												tempstr.append("int ");
												break;
											case BOOLEANt:
												tempstr.append("bool ");
												break;
										}
										tempstr.append(i.first);
										tempstr.append(",");
									}
									auto eiter = tempstr.end();
									eiter--;
									tempstr.erase(eiter);
									out << tempstr;
									out << ")\n{\n";



								}
;


//cgdone
formal_parameter:               LEFTBRACKETS parameter_list RIGHTBRACKETS
								{
									$$ = new(paraInfo);
									for( auto &i : *($2) ){
										$$->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								}
                                | empty
								{
									$$ = new(paraInfo);
									/*-----以上为语义分析部分，完成--------*/
								}
;

//cgdone
parameter_list:                 parameter_list SEMICOLON parameter
								{
									$$ = new(paraInfo);
									for( auto &i : *($1) ){
										$$->insert(i);
									}
									for( auto &i : *($3) ){
										$$->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								}
                                | parameter
								{
									$$ = new(paraInfo);
									for( auto &i : *($1) ){
										$$->insert(i);
									}
									/*-----以上为语义分析部分，完成--------*/
								}
;

//cgdone
parameter:                      idlist COLON standard_type
								{
									$$ = new(paraInfo);
									for( auto &i : $1->ids ){
										$$->insert(std::pair<std::string, TYPEKIND>(i,$3));
									}
									/*-----以上为语义分析部分，完成--------*/
								}
;



//cgdone
subprogram_body:                const_declarations var_declarations compound_statement
								{
									out << *($3);
									out << "\n}\n";
								}
;

//cgdone
compound_statement:             BEGINpas statement_list END
								{
									$$ = new(std::string);
									*$$= *$2;
								}
								
;

//jdydone
statement_list:                 statement_list SEMICOLON statement
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append("\n");
									$$->append(*$3);

								}
                                | statement
								{
									$$ = new(std::string);
									$$->append(*$1);
								}
;



statement:                      variable ASSIGNOP expression
								{/*类型检查*/ 
									$$ = new(std::string);
									auto iter = funtab.find(*$1);
									if(  iter != funtab.end() ){
										$$->append("return ");
										$$->append(*$3);
										$$->append(";");
									}else{
										$$ = new(std::string);
										$$->append(*$1);
										$$->append(" = ");
										$$->append(*$3);
										$$->append(";");
									}

									
								}
| procedure_call{$$ = new(std::string);
    $$->append(*$1);
    $$->append(";");}
                                | compound_statement
								{
									$$ = new(std::string);
									$$->append(*$1);
								}
                                | IF expression THEN statement %prec LOWER_THAN_ELSE
								{
									/*类型检查*/ 
									$$ = new(std::string);
									$$->append("if(");
									$$->append(*$2);
									$$->append("){\n");
									$$->append(*$4);
									$$->append("\n");
									$$->append("}");
								}
                                | IF expression THEN statement ELSE statement
								{
									/*类型检查*/
									$$ = new(std::string);
									$$->append("if(");
									$$->append(*$2);
									$$->append("){\n");
									$$->append(*$4);
									$$->append("\n");
									$$->append("}");
									$$->append("else{\n");
									$$->append(*$6);
									$$->append("\n}\n");
								}
                                | CASE expression OF case_body END{$$ = new(std::string);}
                                | WHILE expression DO statement 
								{
									/*类型检查*/ 
									$$ = new(std::string);
									$$->append("while( ");
									$$->append(*$2);
									$$->append(" ){\n");
									$$->append(*$4);
									$$->append("\n}\n");
								}
                                | REPEAT statement_list UNTIL expression{ $$ = new(std::string); }
                                | FOR ID ASSIGNOP expression updown expression DO statement
								{/*类型检查*/
								
								
								$$ = new(std::string);
								/*作用域检查*/
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == $2->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<$2->id_name << '\'' <<" has not been decleared yet.\n";
									}
									/*-----以上为语义分析部分，完成--------*/
                                    $$->append("for");
                                    $$->append("(");
                                    $$->append($2->id_name);
                                    $$->append("=");
                                    $$->append(*$4);
                                    $$->append(";");
                                    if($5==0)
                                    {
                                        $$->append("<");
                                        $$->append(*$6);
                                        $$->append(";");
                                        $$->append($2->id_name);
                                        $$->append("++");
                                    }
                                    else if ($5==1)
                                    {
                                        
                                        $$->append(">");
                                        $$->append(*$6);
                                        $$->append(";");
                                        $$->append($2->id_name);
                                        $$->append("--");

                                    }
                                    $$->append(")");
                                    $$->append("\n");
                                    $$->append("{");
                                    $$->append(*$8);
                                    $$->append("}");
								}
                                | empty { $$ = new(std::string); }
;



//jdydone
variable:                       ID id_varparts
								{
									$$ = new(std::string);
									$$->append($1->id_name);
									/*作用域检查*/
									auto temps = symtab;
									bool flag = 0;
									while( !temps.empty() ){
										if( temps.top().name == $1->id_name){
											flag = 1;
											break;
										}
										else{
											temps.pop();
										}
									}
									//std::cout << "！！！！！ffffffffffffffffstruct decev \n";
									if( flag == 0){
										std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The variable "<< '\'' <<$1->id_name << '\'' <<" has not been decleared yet.\n";
									}else{
										/*在这个地方进行数组维数检查，结构体成员变量检查*/
										//std::cout << "！！！！！ffdsfdsfgdffffffffstruct decev \n";
										//先进行结构体成员变量检查
										if( temps.top().kind  == RECORDt ){
											for( auto &i : $2->ss){
												$$->append(".");
												$$->append(i);
											}
											//std::cout << "！！！！！struct decev \n";
											auto temppp = temps.top().tinfop;
											for( auto &i : $2->ss){
												auto iter =  temppp->records.find(i);
												if( iter  != temppp->records.end() ){
													temppp = iter->second;
												}else{
													std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The member variables "<< '\'' << i << '\'' <<" has not been decleared yet.\n";
													break;
												}
											}
										}//结构体成员变量检查
										else{
											//std::cout << "！！！！！ffdsfdsfgdasdfasfdasfasdfasfasasdffffffffffstruct decev \n";
											if( temps.top().kind  == ARRAYt ){
												$$->append("[");
												for( auto &i : $2->ss){
												$$->append(i);
												}
												$$->append("]");
												if( temps.top().tinfop->periods.size()/2 != $2->dimension){
													std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The array variable "<< '\'' << $1->id_name << '\'' <<"\'s dimension is not correct.\n";
												}
											}//数组维数检查
										}
										

									}
									//std::cout << "！！！！hhhhhhhhhhhhhhhhhh！struct decev \n";

									/*-----以上为语义分析部分，完成--------*/

								}
;


//jdydone
id_varparts:                    id_varparts id_varpart
								{
									$$ = new(id_varpartsAttri);
									for( auto & i: $1->ss ){
										$$->ss.push_back(i);
									}
									$$->ss.push_back($2->s);
									$$->dimension = $2->dimension;
									/*-----以上为语义分析部分，完成--------*/
								}
                                | empty
								{
									$$ = new(id_varpartsAttri);
									/*-----以上为语义分析部分，完成--------*/
								}
;

//jdydone
id_varpart:                     LEFTSQUBRACKETS expression_list RIGHTSQUBRACKETS
								{
									$$ = new(id_varpartAttri);
									$$->dimension = $2->dimension;
									/*-----以上为语义分析部分，完成--------*/

									$$->s = $2->outcode;
								}
                                | DOT ID
								{
									$$ = new(id_varpartAttri);
									$$->s = $2->id_name;
									/*-----以上为语义分析部分，完成--------*/
								}
;



case_body:                      branch_list
                                | empty
;

branch_list:                    branch_list SEMICOLON branch
                                | branch
;


branch:                         const_list COLON statement
;

const_list:                     const_list COMMA const_value
                                | const_value   
;


procedure_call:                 ID
								{
									auto iter1 = funtab.find($1->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find($1->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << $1->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != 0){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != 0){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/
                                    $$=new(std::string);
                                    $$->append($1->id_name);
								}
                                | ID LEFTBRACKETS expression_list RIGHTBRACKETS
								{
									auto iter1 = funtab.find($1->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find($1->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << $1->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != $3->dimension){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != $3->dimension){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/
                                    $$=new(std::string);
                                    $$->append($1->id_name);
                                    $$->append("(");
                                    $$->append($3->outcode);
                                    $$->append(")");
								}
;


updown:                         TO {$$=0;}
| DOWNTO{$$=1;}
;


//jdydone
expression_list:                expression_list COMMA expression
								{
									$$ = new(expression_listAttri);
									$$->dimension = $1->dimension  + 1;
									/*-----以上为语义分析部分，完成--------*/
									$$->outcode.append($1->outcode);
									$$->outcode.append(",");
									$$->outcode.append(*$3)
								}
                                | expression
								{
									$$ = new(expression_listAttri);
									$$->dimension = 1;
									/*-----以上为语义分析部分，完成--------*/

									$$->outcode.append(*$1);
								}
;


//jdydone
expression:                     simple_expression RELOP simple_expression
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" ");
									if( strcmp($2->id_name.c_str(),"<") ){
										$$->append("<");
									}else if(strcmp($2->id_name.c_str(),">")){
										$$->append(">");
									}else if(strcmp($2->id_name.c_str(),"<=")){
										$$->append("<=");
									}else if(strcmp($2->id_name.c_str(),">=")){
										$$->append(">=");
									}else{//"<>"
										$$->append("!=");
									}
									$$->append(" ");
									$$->append(*$3);
								}
                                | simple_expression EQUSIGN simple_expression
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" ");
									$$->append("==");
									$$->append(" ");
									$$->append(*$3);

								}
                                | simple_expression{
									$$ = new(std::string);
									$$->append(*$1);
								}
;


//jdydone
simple_expression:              term
								{
									$$ = new(std::string);
									$$->append(*$1);
								}
                                | PLUS term
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(" + ");
									$$->append(*$2);
									//$$->append(")");
								}
                                | MINUS term
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(" - ");
									$$->append(*$2);
									//$$->append(")");
								}
                                | simple_expression PLUS term
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(*$1);
									$$->append(" + ");
									$$->append(*$3);
									//$$->append(")");
								}
                                | simple_expression MINUS term
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(*$1);
									$$->append(" - ");
									$$->append(*$3);
									//$$->append(")");
								}
                                | simple_expression OR term
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(*$1);
									$$->append(" || ");
									$$->append(*$3);
									//$$->append(")");
								}
;

//jdydone
term:                           factor
								{
									$$ = new(std::string);
									$$->append(*$1);
								}
                                | term MULTIPLY factor
								{
									$$ = new(std::string);
									//$$->append("(");
									$$->append(*$1);
									$$->append(" * ");
									$$->append(*$3);
									//$$->append(" ) ");
								}
                                | term DIVISION factor
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" / ");
									$$->append(*$3);
								}
                                | term DIV factor
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" / ");
									$$->append(*$3);
								}
                                | term MOD factor
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" % ");
									$$->append(*$3);
								}
                                | term AND factor
								{
									$$ = new(std::string);
									$$->append(*$1);
									$$->append(" && ");
									$$->append(*$3);
								}
;

//jdydone
factor:                         NUM
								{
									$$ = new(std::string);
									std::ostringstream strstemp;
									strstemp << $1->val;
									std::string strnum = strstemp.str();
									$$->append(strnum);
								}
                                | variable
								{
									$$ = new(std::string);
									$$->append(*$1);
								}
                                | ID LEFTBRACKETS expression_list RIGHTBRACKETS
								{
									auto iter1 = funtab.find($1->id_name);
									if( iter1 == funtab.end() ){
										auto iter2 = protab.find($1->id_name);
										if( iter2 == protab.end() ){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure or function "<< '\'' << $1->id_name << '\'' <<"has not been declared.\n";
										}else{
											if( iter2->second.size() != $3->dimension){
												std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The procedure "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
											}
										}
									}else{
										if( iter1->second.parainfo.size() != $3->dimension){
											std::cerr << "ERROR: Line " <<yylineno << "\t"<<"The function "<< '\'' << $1->id_name << '\'' <<"\'sParameter does not match.\n";
										}
									}
									/*-----以上为语义分析部分，完成--------*/

									$$ = new(std::string);
									$$->append($1->id_name);
									$$->append("(");
									$$->append($3->outcode);
									$$->append(")");
								}
                                | LEFTBRACKETS expression RIGHTBRACKETS
								{
									$$ = new(std::string);
									$$->append("(");
									$$->append(*$2);
									$$->append(")");
								}
                                | NOT factor
								{
									$$ = new(std::string);
									$$->append("!");
									$$->append(*$2);
								}
;

empty:

%%

#include <cctype>
#include <cstdio>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>



int main (int argc, char** argv)
{
	out.open("result.c",std::ios::out);
	if( argc <= 1 ){
		return yyparse ();
	}else{
		FILE * file = fopen (argv[1], "r");
		if( !file ){
			perror(argv[1]);
			return 1;
		}else{
			yyin = file;
			return yyparse();
		}
	}
}


/* Called by yyparse on error.  */

void yyerror (char const *s)
{
	std::cout << "line " << yylineno;
	fprintf (stderr, "%s\n", s);
}

std::string record2struct(std::pair<std::string, typeAttri> recordin) 
{
    std::string result;
    result.append("struct ");
    result.append(recordin.first);
    result.append(" {\n");
    for (auto &i : recordin.second.records) {
        
        switch ((i.second)->kind) {
            case REALt:
            result.append("double ");
            result.append(i.first);
            result.append(";\n");
            break;
            case CHARt:
            result.append("char ");
            result.append(i.first);
            result.append(";\n");
            break;
            case BOOLEANt:
            result.append("bool ");
            result.append(i.first);
            result.append(";\n");
            break;
            case INTEGERt:
            result.append("int ");
            result.append(i.first);
            result.append(";\n");
            break;
            case RECORDt:
            result.append(record2struct(std::pair<std::string, typeAttri>(i.first, *(i.second))));
            break;
            case ARRAYt:
            break;
        }
        
    }
    result.append("}");
    result.append(recordin.first);
    result.append(";\n");
    return result;
}

