%code requires{
    #include <cstdio>
    #include <cstdlib>
    #include <memory>

    #include "common/node.hpp"
    #include "common/token.hpp"

    namespace common_impl = tl::common;
}

%code {       
    std::shared_ptr<common_impl::Node>programBlock; /* the top level root node of our final AST */
    extern int yylex();
    void yyerror(const char *s) { std::printf("Error: %s\n", s);std::exit(1); }
}

/* Represents the many different ways we can access our data */
%union{
    common_impl::Node* node;
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
    switch: SY_SWITCH

*/
%token <token_info> KW_IF KW_ELSE KW_WHILE

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <node> stmt lt_init single_val literal_val
%type <block> program block
%type <si64_list_node> si64_lt si64_lt_init shape_lt
%type <fp64_list_node> fp64_lt fp64_lt_init
%type <str_list_node> str_lt str_lt_init
%type <var_decl_node>var_decl
%type <value_expr> value_expr
%type <assign_stmt> assign_stmt
%type <slice_list_node> slice_lt
%type <slice_expr> slice_expr
%type <if_else_stmt> if_else_stmt if_sub_stmt

%left KW_ELSE
%left SY_COMMA
%left SY_CEQ SY_CNE SY_CGT SY_CLT SY_CGE SY_CLE
%left SY_PLUS SY_MINUS
%left SY_MUL SY_DIV

/* Operator precedence for mathematical operators */

%start program
%% 
program : block { programBlock.reset($1); }
         ;
                
block : stmt { 
                $$=new common_impl::Block();
                $$->AppendNode($1);
                }
         | block stmt { $1->AppendNode($2); }
         ;

stmt :var_decl {$$=$1;}
    | assign_stmt{$$=$1;}
    | if_else_stmt {$$=$1;}
    ;

var_decl : T_IDENTIFIER shape_lt T_IDENTIFIER lt_init SY_SEMICOLON
        {
            $$=new common_impl::VarDeclarationNode(
                $1->GetIdent(),
                $2,
                $3->GetIdent(),
                $4
            );
        }
        | T_IDENTIFIER shape_lt T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON
        {
            $$=new common_impl::VarDeclarationNode(
                $1->GetIdent(),
                $2,
                $3->GetIdent(),
                $5
            );
        }
        ;
assign_stmt : T_IDENTIFIER SY_EQUAL value_expr SY_SEMICOLON
            {
                $$ = new common_impl::AssignStatement($1->GetIdent(),$3);
            }
            ;

if_else_stmt : if_sub_stmt{ $$=$1;}
            | if_sub_stmt KW_ELSE SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                $$ = $1;
                $1->AppendIfElse(nullptr,$4);
            }
            ;

if_sub_stmt : KW_IF SY_LEFT_PAREN value_expr SY_RIGHT_PAREN SY_LEFT_BRACE block SY_RIGHT_BRACE
            {
                $$ = new common_impl::IfElseStatement();
                $$->AppendIfElse($3,$6);
            }
            | if_sub_stmt KW_ELSE if_sub_stmt
            {
                $$ = new common_impl::IfElseStatement();
                $$ -> AppendIfElse($1);
                $$ -> AppendIfElse($3);
            }
            ;

value_expr : single_val  { $$= new common_impl::ExpressionNode($1,-1,nullptr); }
            | value_expr SY_MUL value_expr { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_DIV value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_PLUS value_expr { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_MINUS value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CEQ value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CNE value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CGT value_expr { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CLT value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CGE value_expr  { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            | value_expr SY_CLE value_expr { $$= new common_impl::ExpressionNode($1,$2->GetTokenId(),$3);}
            ;

slice_expr : T_IDENTIFIER SY_LEFT_BRACKET slice_lt SY_RIGHT_BRACKET
            {
                $$ = new common_impl::SliceExpression($1->GetIdent(),$3);
            }
            ;

slice_lt : V_SI64 
            {
                $$=new common_impl::SliceList();
                $$->AppendIndex($1->GetValue<int64_t>());
            }
            | V_SI64 SY_COLON 
            {
                $$=new common_impl::SliceList();
                $$->AppendIndex($1->GetValue<int64_t>(),common_impl::SliceList::Position::TO_END);
            }
            | SY_COLON V_SI64 
            {
                $$=new common_impl::SliceList();
                $$->AppendIndex(common_impl::SliceList::Position::TO_BEGIN,$1->GetValue<int64_t>());
            }
            | SY_COLON
            {
                $$=new common_impl::SliceList();
                $$->AppendIndex(common_impl::SliceList::Position::TO_BEGIN,
                                    common_impl::SliceList::Position::TO_END);
            }
            | V_SI64 SY_COLON V_SI64 
            {
                $$=new common_impl::SliceList();
                $$->AppendIndex($1->GetValue<int64_t>(),$3->GetValue<int64_t>());
            }
            | slice_lt SY_COMMA slice_lt 
            {
                $$ = new common_impl::SliceList();
                $$->AppendIndex($1,$3);
                free($1);
                free($3);
            }
            ;


lt_init : %empty {$$=nullptr;}
        | si64_lt_init{$$=$1;}
        | fp64_lt_init{$$=$1;}
        | str_lt_init{$$=$1;}
        ;

str_lt_init :SY_LEFT_BRACE str_lt SY_RIGHT_BRACE {$$=$2;}
            ;

fp64_lt_init : SY_LEFT_BRACE fp64_lt SY_RIGHT_BRACE {$$=$2;}
            ;

si64_lt_init :SY_LEFT_BRACE si64_lt SY_RIGHT_BRACE {$$=$2;}
            ;

shape_lt : %empty {$$=nullptr;}
        | SY_LEFT_BRACKET si64_lt SY_RIGHT_BRACKET {$$=$2;}
        ;

si64_lt : V_SI64 {
                    $$=new common_impl::SI64ListNode();
                    $$->Append($1->GetValue<int64_t>());
                }
        | si64_lt SY_COMMA V_SI64
                {
                    $1->Append($3->GetValue<int64_t>());
                }
        ;

fp64_lt : V_FP64{
                    $$=new common_impl::FP64ListNode();
                    $$->Append($1->GetValue<double>());
                }
        | fp64_lt SY_COMMA V_FP64
                {
                    $1->Append($3->GetValue<double>());
                }
        ;

str_lt : V_STR{
                    $$=new common_impl::STRListNode();
                    $$->Append($1->GetValue<std::string>());
                }
        | str_lt SY_COMMA V_STR
                {
                    $1->Append($3->GetValue<std::string>());
                }
        ;


single_val: literal_val { $$=$1;}
            | T_IDENTIFIER {$$ =new common_impl::IdentifierNode($1->GetIdent()); }
            | slice_expr {$$=$1;}
            ;

literal_val: V_SI64     {$$ = new common_impl::SI64Node($1->GetValue<int64_t>());}
            | V_FP64    {$$ = new common_impl::FP64Node($1->GetValue<double>());}
            | V_STR     {$$ = new common_impl::StrNode($1->GetValue<std::string>());}
        ;
%%
