%code requires{
    #include <cstdio>
    #include <cstdlib>
    #include <memory>

    #include "common/node.hpp"
    #include "common/token.hpp"
    #include "common/location.hpp"

    namespace common_impl = tl::common;
}

%code {       
    std::shared_ptr<common_impl::ModuleNode>program; /* the top level root node of our final AST */
    extern int yylex();
    void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
}

/* Represents the many different ways we can access our data */
%union{
    common_impl::Node* node;
    common_impl::ModuleNode* module;
    common_impl::Block* block;
    common_impl::SI64ListNode* si64_list_node;
    common_impl::FP64ListNode* fp64_list_node;
    common_impl::STRListNode* str_list_node;
    common_impl::VarDeclarationNode* var_decl_node;
    common_impl::TokenInfo* token_info;
    common_impl::ExpressionNode* value_expr;
    common_impl::AssignStatement* assign_stmt;
    common_impl::SliceList* slice_list_node;
    common_impl::SliceExpression* slice_expr;
    common_impl::IfElseStatement* if_else_stmt;
    common_impl::WhileStatement* while_stmt;
    common_impl::ArgumentList* arg_list;
    common_impl::FunctionDeclaration* func_decl;
    common_impl::ReturnStatement* return_stmt;
    common_impl::ExpressionList* expr_list;
    common_impl::FunctionCall* func_call;
    common_impl::BreakStatement* break_stmt;
}


/*
    operator: (element)+、-、*、/
            (broadcast)@+、@-、@*、@/
*/
%token <token_info> SY_PLUS SY_MINUS SY_MUL SY_DIV
%token <token_info> BOP_PLUS BOP_MINUS BOP_MUL BOP_DIV

/*
    =               T_EQUAL
    ==              T_CEQ
    !=              T_CNE
    >               T_CGT
    <               T_CLT
    >=              T_CGE
    <=              T_CLE

*/
%token <token_info> SY_EQUAL SY_CEQ SY_CNE SY_CGT SY_CLT SY_CGE SY_CLE

/*
    [   ]
    (   )
*/
%token <token_info> SY_LEFT_BRACKET SY_RIGHT_BRACKET
%token <token_info> SY_COMMA //,
%token <token_info> SY_COLON //:
%token <token_info> SY_LEFT_BRACE SY_RIGHT_BRACE // {}
%token <token_info> SY_SEMICOLON //;
%token <token_info> SY_LEFT_PAREN SY_RIGHT_PAREN

/*
    V_SI64: 12,22

*/

%token <token_info> V_SI64 V_FP64 V_STR

/*
    identifier
*/

%token <token_info> T_IDENTIFIER

/*
    if else while return

*/
%token <token_info> KW_IF KW_ELSE KW_WHILE KW_RETURN KW_BREAK

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <node> stmt lt_init_with_empty single_val literal_val
%type <block> block
%type <module> module program
%type <si64_list_node> si64_lt si64_lt_init shape_lt_with_empty
%type <fp64_list_node> fp64_lt fp64_lt_init
%type <str_list_node> str_lt str_lt_init
%type <var_decl_node>var_decl
%type <value_expr> value_expr value_expr_with_empty
%type <assign_stmt> assign_stmt
%type <slice_list_node> slice_lt
%type <slice_expr> slice_expr
%type <if_else_stmt> if_else_stmt if_sub_stmt
%type <while_stmt> while_stmt
%type <arg_list> formal_args_lt_with_empty
%type <func_decl> func_decl
%type <return_stmt> return_stmt
%type <expr_list> actual_args_lt_with_empty
%type <func_call> func_call
%type <break_stmt> break_stmt

%left KW_ELSE
%left SY_COMMA
%left SY_CEQ SY_CNE SY_CGT SY_CLT SY_CGE SY_CLE
%left SY_PLUS SY_MINUS
%left SY_MUL SY_DIV

/* Operator precedence for mathematical operators */

%start program
%% 
program : module { program.reset($1);}

module : func_decl 
                {
                    $$ = new common_impl::ModuleNode(
                        "module",$1->GetLocation());
                    $$->Append($1); 
                }
        | module func_decl 
                {
                    $$ = $1;
                    $$->Append($2);
                }
         ;
                
block : stmt { 
                $$=new common_impl::Block("block",$1->GetLocation());
                $$->Append($1);
                }
         | block stmt { $1->Append($2); }
         ;

stmt :var_decl {$$=$1;}
    | assign_stmt{$$=$1;}
    | if_else_stmt {$$=$1;}
    | while_stmt {$$=$1;}
    | return_stmt {$$=$1;}
    | break_stmt {$$=$1;}
    ;

var_decl : T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER lt_init_with_empty SY_SEMICOLON
        {
            common_impl::Location loc=$1->GetLocation();
            loc.UpdateLocation($5->GetLocation());
            $$=new common_impl::VarDeclarationNode(
                "var_decl",
                loc,
                $1->GetIdent(),
                std::shared_ptr<common_impl::SI64ListNode>($2),
                $3->GetIdent(),
                std::shared_ptr<common_impl::Node>($4),
                nullptr
            );
        }
        | T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON
        {
            common_impl::Location loc=$1->GetLocation();
            loc.UpdateLocation($6->GetLocation());
            $$=new common_impl::VarDeclarationNode(
                "var_decl",
                loc,
                $1->GetIdent(),
                std::shared_ptr<common_impl::SI64ListNode>($2),
                $3->GetIdent(),
                nullptr,
                std::shared_ptr<common_impl::ExpressionNode>($5)
            );
        }
        ;

assign_stmt : T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON
            {
                common_impl::Location loc=$1->GetLocation();
                loc.UpdateLocation($4->GetLocation());
                $$ = new common_impl::AssignStatement(
                    "assign_stmt",
                    loc,
                    $1->GetIdent(),
                    std::shared_ptr<common_impl::ExpressionNode>($3)
                );
            }
            ;

if_else_stmt : if_sub_stmt{ $$=$1;}
            | if_sub_stmt KW_ELSE SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                common_impl::Location loc=$1->GetLocation();
                loc.UpdateLocation($5->GetLocation());
                $$ = new common_impl::IfElseStatement(
                    "ifelse_stmt",
                    loc
                );
                $$->Append($1);
                $$->Append(nullptr,$4);
            }
            ;

while_stmt : KW_WHILE SY_LEFT_PAREN value_expr SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                common_impl::Location loc=$1->GetLocation();
                loc.UpdateLocation($7->GetLocation());
                $$ = new common_impl::WhileStatement(
                    "while_stmt",
                    loc,
                    std::shared_ptr<common_impl::ExpressionNode>($3),
                    std::shared_ptr<common_impl::Block>($6)
                );
            }
            ;

func_decl : T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER SY_LEFT_PAREN formal_args_lt_with_empty SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                auto loc=$1->GetLocation();
                loc.UpdateLocation($9->GetLocation());
                $$ = new common_impl::FunctionDeclaration(
                    "func_decl",
                    loc,
                    $1->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>($2),
                    $3->GetIdent(),
                    std::shared_ptr<common_impl::ArgumentList>($5),
                    std::shared_ptr<common_impl::Block>($8)
                );
            }
            ;
return_stmt : KW_RETURN value_expr_with_empty SY_SEMICOLON
            {
                common_impl::Location loc = $1->GetLocation();
                loc.UpdateLocation($3->GetLocation());
                $$ = new common_impl::ReturnStatement(
                    "return_stmt",
                    loc,
                    std::shared_ptr<common_impl::ExpressionNode>($2)
                );
            }
            ;

break_stmt : KW_BREAK SY_SEMICOLON
            {
                auto loc=$1->GetLocation();
                loc.UpdateLocation($2->GetLocation());
                $$=new common_impl::BreakStatement("break_stmt",loc);
            }
            ;

formal_args_lt_with_empty :  %empty {$$=nullptr;}
            |T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER 
            { 
                auto loc=$1->GetLocation();
                loc.UpdateLocation($3->GetLocation());
                $$= new common_impl::ArgumentList(
                    "arg",
                    loc
                );
                $$->Append(
                    $1->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>($2),
                    $3->GetIdent(),
                    loc
                );
            }
        | formal_args_lt_with_empty SY_COMMA T_IDENTIFIER shape_lt_with_empty T_IDENTIFIER
            {
                common_impl::Location loc = $1->GetLocation();
                loc.UpdateLocation($5->GetLocation());
                $$ = $1;
                $$->Append(
                    $3->GetIdent(),
                    std::shared_ptr<common_impl::SI64ListNode>($4),
                    $5->GetIdent(),
                    loc    
                );
            }
        ;

if_sub_stmt : KW_IF SY_LEFT_PAREN value_expr SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                auto loc = $1->GetLocation();
                loc.UpdateLocation($7->GetLocation());
                $$ = new common_impl::IfElseStatement(
                    "ifelse+_stmt",
                    loc
                );
                $$->Append($3,$6);
            }
            | if_sub_stmt KW_ELSE if_sub_stmt
            {
                $$ = $1;
                $$ -> Append($3);
            }
            ;

func_call : T_IDENTIFIER SY_LEFT_PAREN actual_args_lt_with_empty SY_RIGHT_PAREN
            {
                common_impl::Location loc=$1->GetLocation();
                loc.UpdateLocation($4->GetLocation());
                $$=new common_impl::FunctionCall(
                    "func_call",
                    loc,
                    $1->GetIdent(),
                    std::shared_ptr<common_impl::ExpressionList>($3)
                );
            }
            ;
// ExpressionList
actual_args_lt_with_empty : %empty {$$=nullptr;} 
            | value_expr 
            {
                $$=new common_impl::ExpressionList(
                    "expr_lt",
                    $1->GetLocation()
                );
                $$->Append($1);
            }
            | actual_args_lt_with_empty SY_COMMA value_expr
            {
                $$=new common_impl::ExpressionList(
                    "expr_lt",
                    $1->GetLocation()
                );
                $$->Append($1);
                $$->Append($3);
            }
            ;
// ExpressionNode
value_expr_with_empty : %empty {$$=nullptr;}
                        | value_expr{$$=$1;}
                        ;
// ExpressionNode
value_expr : single_val  
                {
                    common_impl::Location loc = $1->GetLocation();
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        -1,
                        nullptr
                    ); 
                }
            | value_expr SY_MUL value_expr 
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_DIV value_expr
                { 
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_PLUS value_expr 
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_MINUS value_expr  
                { 
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CEQ value_expr  
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CNE value_expr  
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CGT value_expr 
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CLT value_expr  
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CGE value_expr  
                {
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        std::string("expr"),
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            | value_expr SY_CLE value_expr 
                { 
                    common_impl::Location loc=$1->GetLocation();
                    loc.UpdateLocation($3->GetLocation());
                    $$= new common_impl::ExpressionNode(
                        "expr",
                        loc,
                        std::shared_ptr<common_impl::Node>($1),
                        $2->GetTokenId(),
                        std::shared_ptr<common_impl::Node>($3)
                    );
                }
            ;
// SliceExpression
slice_expr : T_IDENTIFIER SY_LEFT_BRACKET slice_lt SY_RIGHT_BRACKET
            {
                common_impl::Location loc = $1->GetLocation();
                loc.UpdateLocation($4->GetLocation());

                $$ = new common_impl::SliceExpression(
                    std::string("slice_expr"),
                    loc,
                    $1->GetIdent(),
                    std::shared_ptr<common_impl::SliceList>($3)
                );
            }
            ;
// SliceList
slice_lt : V_SI64 
            {
                $$ = new common_impl::SliceList(
                    std::string("slice_lt"),
                    $1->GetLocation()
                );
                $$->Append($1->GetValue<int64_t>(),$1->GetLocation());
            }
            | V_SI64 SY_COLON 
            {
                $$=new common_impl::SliceList(
                    std::string("slice_lt"),
                    $2->GetLocation()
                );
                $$->Append(
                        $1->GetValue<int64_t>(),common_impl::SliceList::Position::TO_END,
                        $1->GetLocation()
                    );
            }
            | SY_COLON V_SI64 
            {
                $$=new common_impl::SliceList(
                    std::string("slice_lt"),
                    $1->GetLocation()
                );
                $$->Append(
                    common_impl::SliceList::Position::TO_BEGIN,$2->GetValue<int64_t>(),
                    $2->GetLocation()
                );
            }
            | SY_COLON
            {
                $$=new common_impl::SliceList(
                    std::string("slice_lt"),
                    $1->GetLocation()
                );
                $$->Append(
                    common_impl::SliceList::Position::TO_BEGIN,
                    common_impl::SliceList::Position::TO_END,
                    $1->GetLocation()
                );
            }
            | V_SI64 SY_COLON V_SI64 
            {
                $$=new common_impl::SliceList(
                    std::string("slice_lt"),
                    $1->GetLocation()
                );
                $$->Append(
                    $1->GetValue<int64_t>(),
                    $3->GetValue<int64_t>(),
                    $3->GetLocation()
                );
            }
            | slice_lt SY_COMMA slice_lt 
            {
                $$ = new common_impl::SliceList(
                    std::string("slice_lt"),
                    $1->GetLocation()
                );
                $$->Append($1,$3);
            }
            ;


lt_init_with_empty : %empty {$$=nullptr;}
        | si64_lt_init{$$=$1;}
        | fp64_lt_init{$$=$1;}
        | str_lt_init{$$=$1;}
        ;

// STRListNode
str_lt_init :SY_LEFT_BRACE str_lt SY_RIGHT_BRACE 
                {
                    $$ = $2;
                    $$->GetLocation().UpdateLocation($1->GetLocation());
                    $$->GetLocation().UpdateLocation($3->GetLocation());
                }
            ;

fp64_lt_init : SY_LEFT_BRACE fp64_lt SY_RIGHT_BRACE 
                {
                    $$ = $2;
                    $$->GetLocation().UpdateLocation($1->GetLocation());
                    $$->GetLocation().UpdateLocation($3->GetLocation());
                }
            ;

si64_lt_init :SY_LEFT_BRACE si64_lt SY_RIGHT_BRACE 
                {
                    $$ = $2;
                    $$->GetLocation().UpdateLocation($1->GetLocation());
                    $$->GetLocation().UpdateLocation($3->GetLocation());
                }
            ;

shape_lt_with_empty : %empty {$$=nullptr;}
        | SY_LEFT_BRACKET si64_lt SY_RIGHT_BRACKET 
                {
                    $$ = $2;
                    $$->GetLocation().UpdateLocation($1->GetLocation());
                    $$->GetLocation().UpdateLocation($3->GetLocation());
                }
        ;

si64_lt : V_SI64 {
                    $$=new common_impl::SI64ListNode(
                        "si64_lt",
                        $1->GetLocation()
                    );
                    $$->Append($1->GetValue<int64_t>(),$1->GetLocation());
                }
        | si64_lt SY_COMMA V_SI64
                {
                    $$ = $1;
                    $1->Append(
                        $3->GetValue<int64_t>(),
                        $3->GetLocation()
                    );
                }
        ;

fp64_lt : V_FP64{
                    $$=new common_impl::FP64ListNode(
                        "fp64_list",
                        $1->GetLocation()
                    );
                    $$->Append($1->GetValue<double>(),$1->GetLocation());
                }
        | fp64_lt SY_COMMA V_FP64
                {
                    $$ = $1;
                    $1->Append(
                            $3->GetValue<double>(),
                            $3->GetLocation()
                        );
                }
        ;

str_lt : V_STR{
                    $$=new common_impl::STRListNode(
                        "str_list",
                        $1->GetLocation()
                    );
                    $$->Append($1->GetValue<std::string>(),$1->GetLocation());
                }
        | str_lt SY_COMMA V_STR
                {
                    $$ = $1;
                    $1->Append(
                            $3->GetValue<std::string>(),
                            $1->GetLocation()
                        );
                }
        ;

// Node*
single_val: literal_val { $$=$1;}
            | T_IDENTIFIER 
                {
                    $$ =new common_impl::IdentifierNode(
                            "identifier",
                            $1->GetLocation(),
                            $1->GetIdent()
                        ); 
                }
            | slice_expr {$$=$1;}
            | func_call {$$=$1;}
            ;

// Node*
literal_val: V_SI64
                {
                    $$ = new common_impl::SI64Node(
                        std::string("si64"),
                        $1->GetLocation(),
                        $1->GetValue<int64_t>()
                    );
                }
            | V_FP64
                {
                    $$ = new common_impl::FP64Node(
                        std::string("fp64"),
                        $1->GetLocation(),
                        $1->GetValue<double>()
                    );
                }
            | V_STR
                {
                    $$ = new common_impl::StrNode(
                        std::string("str"),
                        $1->GetLocation(),
                        $1->GetValue<std::string>()
                    );
                }
        ;
%%
