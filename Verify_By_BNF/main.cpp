#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
/************************************************************************
* N.Kozak // Lviv'2024-2025 // example syntax analysis by boost::spirit *
*                              file: one_file__x86_Debug.cpp            *
*                                                (0.04v/draft version ) *
*************************************************************************/
#include "stdio.h"
#include <iostream>
#include <sstream>  // for std::ostringstream
#include <string>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp> //

#define CW_GRAMMAR cwgrammar

//#define DEBUG__IF_ERROR

#define RERUN_MODE

#define DEFAULT_INPUT_FILE "..../base_test_programs_2025/file1.k09"
//#define DEFAULT_INPUT_FILE "../other_test_programs_2025/file3.k09"

#define MAX_TEXT_SIZE 8192

namespace qi = boost::spirit::qi;
namespace phx = boost::phoenix;

#define SAME_RULE(RULE) ((RULE) | (RULE))
template <typename Iterator>
struct cwgrammar : qi::grammar<Iterator> {
    cwgrammar(std::ostringstream& error_stream) : cwgrammar::base_type(tokens_in_program), error_stream_(error_stream) {
        keyword =
            tokenINTEGER16 |
            tokenCOMMA |
            tokenNOT |
            tokenAND |
            tokenOR |
            tokenEQUAL |
            tokenNOTEQUAL |
            tokenLESSOREQUAL |
            tokenGREATEROREQUAL |
            tokenPLUS |
            tokenMUL |
            tokenDIV |
            tokenMOD |
            tokenGROUPEXPRESSIONBEGIN |
            tokenGROUPEXPRESSIONEND |
            tokenLRBIND |
            tokenMINUS |
            tokenELSE |
            tokenIF |
            tokenWHILE |
            tokenCONTINUE |
            tokenBREAK |
            tokenGET |
            tokenPUT |
            tokenNAME |
            tokenDATA |
            tokenBEGIN |
            tokenEND |
            tokenBEGINBLOCK |
            tokenENDBLOCK |
            tokenLEFTSQUAREBRACKETS |
            tokenRIGHTSQUAREBRACKETS |
            tokenSEMICOLON;
        tokens_in_program = SAME_RULE(token_iteration);
        token = keyword | ident | value;
        token_iteration = token >> token_iteration | "";
        digit = digit_0 | non_zero_digit;
        digit_optional = digit | "";
        non_zero_digit = digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
        unsigned_value = (non_zero_digit >> digit_optional ) | digit_0 >> BOUNDARIES;
        value = sign_optional >> unsigned_value >> BOUNDARIES;
        letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;
        letter_in_upper_case = A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z;
        ident = letter_in_lower_case >> letter_in_lower_case >> letter_in_lower_case >> letter_in_lower_case >> STRICT_BOUNDARIES;
        sign = sign_plus | sign_minus;
        sign_optional = sign | "";
        sign_plus = SAME_RULE(tokenPLUS);
        sign_minus = SAME_RULE(tokenMINUS);
        digit_0 = '0';
        digit_1 = '1';
        digit_2 = '2';
        digit_3 = '3';
        digit_4 = '4';
        digit_5 = '5';
        digit_6 = '6';
        digit_7 = '7';
        digit_8 = '8';
        digit_9 = '9';
        tokenINTEGER16 = "Integer" >> STRICT_BOUNDARIES;
        tokenCOMMA = "," >> BOUNDARIES;
        tokenNOT = "!!" >> STRICT_BOUNDARIES;
        tokenAND = "&&" >> STRICT_BOUNDARIES;
        tokenOR = "||" >> STRICT_BOUNDARIES;
        tokenEQUAL = "==" >> BOUNDARIES;
        tokenNOTEQUAL = "!=" >> BOUNDARIES;
        tokenLESSOREQUAL = "Le" >> STRICT_BOUNDARIES;
        tokenGREATEROREQUAL = "Ge" >> STRICT_BOUNDARIES;
        tokenPLUS = "+" >> BOUNDARIES;
        tokenMINUS = "-" >> BOUNDARIES;
        tokenMUL = "Mul" >> BOUNDARIES;
        tokenDIV = "Div" >> STRICT_BOUNDARIES;
        tokenMOD = "Mod" >> STRICT_BOUNDARIES;
        tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
        tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
        tokenLRBIND = "->" >> BOUNDARIES;
        tokenELSE = "Else" >> STRICT_BOUNDARIES;
        tokenIF = "If" >> STRICT_BOUNDARIES;
        tokenWHILE = "While" >> STRICT_BOUNDARIES;
        tokenCONTINUE = "Continue" >> STRICT_BOUNDARIES;
        tokenBREAK = "Break" >> STRICT_BOUNDARIES;
        tokenGET = "Input" >> STRICT_BOUNDARIES;
        tokenPUT = "Output" >> STRICT_BOUNDARIES;
        tokenNAME = "Program" >> STRICT_BOUNDARIES;
        tokenDATA = "Var" >> STRICT_BOUNDARIES;
        tokenBEGIN = "Start" >> STRICT_BOUNDARIES;
        tokenEND = "Finish" >> STRICT_BOUNDARIES;
        tokenBEGINBLOCK = "{" >> BOUNDARIES;
        tokenENDBLOCK = "}" >> BOUNDARIES;
        tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES;
        tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES;
        tokenSEMICOLON = ";" >> BOUNDARIES;
        STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
        BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
        BOUNDARY = BOUNDARY_SPACE | BOUNDARY_TAB | BOUNDARY_CARRIAGE_RETURN | BOUNDARY_LINE_FEED | BOUNDARY_NULL;
        BOUNDARY_SPACE = " ";
        BOUNDARY_TAB = "\t";
        BOUNDARY_CARRIAGE_RETURN = "\r";
        BOUNDARY_LINE_FEED = "\n";
        BOUNDARY_NULL = "\0";
        NO_BOUNDARY = "";
        tokenUNDERSCORE = "_";
        A = "A";
        B = "B";
        C = "C";
        D = "D";
        E = "E";
        F = "F";
        G = "G";
        H = "H";
        I = "I";
        J = "J";
        K = "K";
        L = "L";
        M = "M";
        N = "N";
        O = "O";
        P = "P";
        Q = "Q";
        R = "R";
        S = "S";
        T = "T";
        U = "U";
        V = "V";
        W = "W";
        X = "X";
        Y = "Y";
        Z = "Z";
        a = "a";
        b = "b";
        c = "c";
        d = "d";
        e = "e";
        f = "f";
        g = "g";
        h = "h";
        i = "i";
        j = "j";
        k = "k";
        l = "l";
        m = "m";
        n = "n";
        o = "o";
        p = "p";
        q = "q";
        r = "r";
        s = "s";
        t = "t";
        u = "u";
        v = "v";
        w = "w";
        x = "x";
        y = "y";
        z = "z";

    }
    std::ostringstream& error_stream_;

    qi::rule<Iterator>
        tokens_in_program,
        token_iteration,
        token,
        keyword,
        ident,
        letter_in_lower_case,
        letter_in_upper_case,
        unsigned_value,
        value,
        sign_optional,
        sign,
        sign_plus,
        sign_minus,
        digit,
        digit_optional,
        non_zero_digit,
        //
        tokenCOLON, tokenGOTO, tokenINTEGER16, tokenCOMMA, tokenNOT, tokenAND, tokenOR, tokenEQUAL, tokenNOTEQUAL,
        tokenLESSOREQUAL,
        tokenGREATEROREQUAL,
        tokenLESS,
        tokenGREATER,
        tokenPLUS, tokenMINUS, tokenMUL, tokenDIV, tokenMOD, tokenGROUPEXPRESSIONBEGIN, tokenGROUPEXPRESSIONEND, tokenLRBIND,
        tokenELSE, tokenIF, tokenDO, tokenFOR, tokenTO, tokenDOWNTO, tokenWHILE, tokenCONTINUE, tokenBREAK, tokenEXIT, tokenREPEAT, tokenUNTIL, tokenGET, tokenPUT, tokenNAME, tokenBODY, tokenDATA, tokenBEGIN, tokenEND, tokenBEGINBLOCK, tokenENDBLOCK, tokenLEFTSQUAREBRACKETS, tokenRIGHTSQUAREBRACKETS, tokenSEMICOLON,
        //
        STRICT_BOUNDARIES, BOUNDARIES, BOUNDARY, BOUNDARY_SPACE, BOUNDARY_TAB, BOUNDARY_CARRIAGE_RETURN, BOUNDARY_LINE_FEED, BOUNDARY_NULL,
        NO_BOUNDARY,
        //
        digit_0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9,
        //
        tokenUNDERSCORE,
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
};

template <typename Iterator>
struct cwgrammar_2 : qi::grammar<Iterator> {
#define ADDON_RULES_LIST \
value_type__ident,\
other_declaration_ident____iteration_after_one,\
input__first_part,\
input__second_part,\
output__first_part,\
output__second_part,\
unsigned_value__non_terminal,\
\
statement____iteration_after_two,\
tokenNAME__program_name,\
tokenSEMICOLON__tokenStart,\
tokenDATA__declaration,\
tokenNAME__program_name__tokenSEMICOLON__tokenStart,\
program____part1,\
statement__tokenEnd,\
statement____iteration_after_two__tokenEnd,\
block_statements____part1,/*+ NEW2025*/\
program____part2,\
\
tokenUNTIL__group_expression,\
tokenREPEAT__statement____iteration_after_two,\
tokenREPEAT__statement,\
\
statement_in_while_body_and_if_body____iteration_after_two,\
block_statements_in_while_body_and_if_body____part1,/*+ NEW2025*/\
tokenWhile__expression,\
tokenEnd__tokenWhile,\
tokenWhile__expression__statement_in_while_body_and_if_body,\
tokenWhile__expression__statement_in_while_body_and_if_body____iteration_after_two,\
tokenFOR__cycle_counter_init,\
tokenTO_tokenDOWNTO__cycle_counter_last_value,\
tokenFOR__cycle_counter_init__tokenTO_tokenDOWNTO__cycle_counter_last_value,\
/*cycle_body__tokenSEMICOLON,*/\
\
/*tokenElse__statement_in_while_body_and_if_body,*/\
/*tokenElse__statement_in_while_body_and_if_body____iteration_after_two,*/\
/*tokenIf__tokenGROUPEXPRESSIONBEGIN,*/\
/*expression__tokenGROUPEXPRESSIONEND,*/\
/*tokenIf__tokenGROUPEXPRESSIONBEGIN__expression__tokenGROUPEXPRESSIONEND,*/\
/*body_for_true__body_for_false,*/\
tokenIf__expression,\
tokenIf__expression__body_for_true,\
false_cond_block_without_else,\
false_cond_block_without_else____iteration_after_two,\
tokenIf__expression__body_for_true__false_cond_block_without_else_iteration_after_one,\
\
tokenGROUPEXPRESSIONBEGIN__expression,\
binary_action____iteration_after_two
    cwgrammar_2(std::ostringstream& error_stream) : cwgrammar_2::base_type(program), error_stream_(error_stream) {
        //
        labeled_point = ident >> tokenCOLON;                                                                                       // +
        goto_label = tokenGOTO >> ident;                                                                                           // +
        program_name = SAME_RULE(ident);                                                                                           // + (!)
        value_type = SAME_RULE(tokenInteger);                                                                                    // + (!)
        other_declaration_ident = (tokenComma >> ident);                                                                           // + (!)
        other_declaration_ident____iteration_after_one = other_declaration_ident >> other_declaration_ident____iteration_after_one // + (!)
            | tokenComma >> ident;                                                                                                 // + (!)
        value_type__ident = value_type >> ident;                                                                                   // + (!)
        declaration = value_type__ident >> other_declaration_ident____iteration_after_one                                          // +
            | value_type >> ident;                                                                                         // + (!)
        //
        unary_operator = SAME_RULE(tokenNOT);  // + (!)
        binary_operator = tokenAND             // + (!)
            | tokenOR                          // + (!)
            | tokenEQUAL                       // + (!)
            | tokenNOTEQUAL                    // + (!)
            | tokenLESSOREQUAL                 // + (!)
            | tokenGREATEROREQUAL              // + (!)
            | tokenPLUS                        // + (!)
            | tokenMINUS                       // + (!)
            | tokenMul                         // + (!)
            | tokenDiv                         // + (!)
            | tokenMod;                        // + (!)
        binary_action = binary_operator >> expression; // +
        //
        left_expression = tokenGROUPEXPRESSIONBEGIN__expression >> tokenGROUPEXPRESSIONEND            // + (!)
            | unary_operator >> expression                                                // + (!)
            | ident                                                                       // +
            | value;                                                                      // +
        binary_action____iteration_after_two = binary_action >> binary_action____iteration_after_two  // +
            | binary_action >> binary_action;                        // +
        expression = left_expression >> binary_action____iteration_after_two                          // +
            | left_expression >> binary_action                                                // +
            | tokenGROUPEXPRESSIONBEGIN__expression >> tokenGROUPEXPRESSIONEND                // + (!)
            | unary_operator >> expression                                                    // + (!)
            | ident                                                                           // +
            | value;                                                                          // +
        //
        tokenGROUPEXPRESSIONBEGIN__expression = tokenGROUPEXPRESSIONBEGIN >> expression;     // + (!)
        group_expression = tokenGROUPEXPRESSIONBEGIN__expression >> tokenGROUPEXPRESSIONEND; // + (!)
        //
        bind_right_to_left = ident >> rl_expression; // + (!)
        bind_left_to_right = lr_expression >> ident; // + (!)
        //
#if 0 // OLD
        (-)body_for_true = statement_in_while_body_and_if_body____iteration_after_two >> tokenSEMICOLON                                                                                   // + (!) ( tokenSEMICOLON as nonterminal ! )
            | statement_in_while_body_and_if_body >> tokenSEMICOLON                                                                                                          // + (!) ( tokenSEMICOLON as nonterminal ! )
            | tokenSEMICOLON;                                                                                                                      // + (!) ( tokenSEMICOLON as    terminal ! )
        (-)tokenElse__statement_in_while_body_and_if_body = tokenElse >> statement_in_while_body_and_if_body;                                                                                                       // + (!)
        (-)tokenElse__statement_in_while_body_and_if_body____iteration_after_two = tokenElse >> statement_in_while_body_and_if_body____iteration_after_two;                                                         // + (!)
        (+)body_for_false = tokenElse__statement_in_while_body_and_if_body____iteration_after_two >> tokenSEMICOLON                                                                       // + (!)
            | tokenElse__statement_in_while_body_and_if_body >> tokenSEMICOLON                                                                                              // + (!)
            | tokenElse >> tokenSEMICOLON;                                                                                                        // + (!)
        (-)tokenIf__tokenGROUPEXPRESSIONBEGIN = tokenIf >> tokenGROUPEXPRESSIONBEGIN;                                                                           // + (!)
        (-)expression__tokenGROUPEXPRESSIONEND = expression >> tokenGROUPEXPRESSIONEND;                                                                         // +
        (-)tokenIf__tokenGROUPEXPRESSIONBEGIN__expression__tokenGROUPEXPRESSIONEND = tokenIf__tokenGROUPEXPRESSIONBEGIN >> expression__tokenGROUPEXPRESSIONEND; // +
        (-)body_for_true__body_for_false = body_for_true >> body_for_false;                                                                                     // +
        (+)cond_block = tokenIf__tokenGROUPEXPRESSIONBEGIN__expression__tokenGROUPEXPRESSIONEND >> body_for_true__body_for_false                                // +
            | tokenIf__tokenGROUPEXPRESSIONBEGIN__expression__tokenGROUPEXPRESSIONEND >> body_for_true;                                               // +
#endif
        //NEW2025{//
        tokenIf__expression = tokenIf >> expression;                                                                                                    // + NEW2025
        tokenIf__expression__body_for_true = tokenIf__expression >> block_statements_in_while_body_and_if_body;                                         // + NEW2025
        false_cond_block_without_else = tokenElse >> cond_block;                                                                                                     // + NEW2025
        false_cond_block_without_else____iteration_after_two = false_cond_block_without_else >> false_cond_block_without_else____iteration_after_two                                                  // + NEW2025
            | false_cond_block_without_else >> false_cond_block_without_else;                                                                 // + NEW2025
        tokenIf__expression__body_for_true__false_cond_block_without_else_iteration_after_one = tokenIf__expression__body_for_true >> false_cond_block_without_else____iteration_after_two
            | tokenIf__expression__body_for_true >> false_cond_block_without_else;                        // + NEW2025
        body_for_false = tokenElse >> block_statements_in_while_body_and_if_body;                                                                       // + NEW2025
        cond_block = tokenIf__expression__body_for_true__false_cond_block_without_else_iteration_after_one >> body_for_false
            | tokenIf__expression__body_for_true >> false_cond_block_without_else____iteration_after_two
            | tokenIf__expression__body_for_true >> false_cond_block_without_else
            | tokenIf__expression__body_for_true >> body_for_false
            | tokenIf__expression >> block_statements_in_while_body_and_if_body;                                                                 // + NEW2025


        // cond_block__P1 = tokenIf__expression >> B        
        // B = Bo >>
        // B = Bl >>
        // Bo =
        // Bl = 
        // B = block_statements_in_while_body_and_if_body(:)

//}NEW2025//
        cycle_counter = SAME_RULE(ident);                                                                                                    // + (!)
        rl_expression = tokenRLBIND >> expression;                                                                                           // + (!)
        lr_expression = expression >> tokenLRA;                                                                                           // + (!)
        cycle_counter_init = cycle_counter >> rl_expression                                                                                  // +
            | lr_expression >> cycle_counter;                                                                                 // +
        //cycle_counter_last_value = SAME_RULE(value);                                                                                         // + (!)
        cycle_body = tokenDO >> block_statements // + NEW2025 // statement____iteration_after_two                                                               // + (!)
            | tokenDO >> statement;                                                                                                  // + (!)
        tokenFOR__cycle_counter_init = tokenFOR >> cycle_counter_init;                                                                       // + (!)
        tokenTO_tokenDOWNTO__cycle_counter_last_value = tokenTO >> expression      // + NEW2025 (last value as any expression)                                                         // + (!)
            | tokenDOWNTO >> expression; // + NEW2025 (last value as any expression)  
        tokenFOR__cycle_counter_init__tokenTO_tokenDOWNTO__cycle_counter_last_value = tokenFOR__cycle_counter_init >> tokenTO_tokenDOWNTO__cycle_counter_last_value; // +
        // cycle_body__tokenSEMICOLON = cycle_body >> tokenSEMICOLON;  // + NEW2025                                                                          // + (!)
        forto_cycle = tokenFOR__cycle_counter_init__tokenTO_tokenDOWNTO__cycle_counter_last_value >> cycle_body; // + NEW2025                       // +
        //
        continue_while = tokenContinue >> tokenWhile;                                                                                                       // + (!)
        exit_while = tokenEXIT >> tokenWhile;                                                                                                               // + (!) 
        tokenWhile__expression = tokenWhile >> expression;                                                                                                  // + (!) NEW
        tokenEnd__tokenWhile = tokenEnd >> tokenWhile;                                                                                                      // + (!) NEW
        tokenWhile__expression__statement_in_while_body_and_if_body = tokenWhile__expression >> statement_in_while_body_and_if_body;                                                // + NEW
        tokenWhile__expression__statement_in_while_body_and_if_body____iteration_after_two = tokenWhile__expression >> statement_in_while_body_and_if_body____iteration_after_two;  // + NEW
        while_cycle = tokenWhile__expression__statement_in_while_body_and_if_body____iteration_after_two >> tokenEnd__tokenWhile                                        // + NEW
            | tokenWhile__expression__statement_in_while_body_and_if_body >> tokenEnd__tokenWhile                                                            // + NEW
            | tokenWhile__expression >> tokenEnd__tokenWhile;                                                                                      // + NEW
        //
        tokenUNTIL__group_expression = tokenUNTIL >> expression;                                     // + (!)
        tokenREPEAT__statement____iteration_after_two = tokenREPEAT >> statement____iteration_after_two;   // + (!)
        tokenREPEAT__statement = tokenREPEAT >> statement;                                                 // + (!)
        repeat_until_cycle = tokenREPEAT__statement____iteration_after_two >> tokenUNTIL__group_expression // +
            | tokenREPEAT__statement >> tokenUNTIL__group_expression                       // +
            | tokenREPEAT >> tokenUNTIL__group_expression;                                 // + (!)
        //
        input__first_part = tokenInput >> tokenGROUPEXPRESSIONBEGIN;          // + (!)
        input__second_part = ident >> tokenGROUPEXPRESSIONEND;              // + (!)
        input =
#ifdef DEBUG__IF_ERROR
            qi::eps >
#endif
            input__first_part >> input__second_part;                        // +
#ifdef DEBUG__IF_ERROR
        input.name("input");
        input__first_part.name("input__first_part");
        input__second_part.name("input__second_part");
#endif
        output__first_part = tokenOutput >> tokenGROUPEXPRESSIONBEGIN;         // + (!)
        output__second_part = expression >> tokenGROUPEXPRESSIONEND;        // + (!)
        output = output__first_part >> output__second_part;                 // +
        statement = ident >> rl_expression
            | lr_expression >> ident
            | tokenIf__expression__body_for_true__false_cond_block_without_else_iteration_after_one >> body_for_false        // + NEW2025
            | tokenIf__expression__body_for_true >> false_cond_block_without_else____iteration_after_two                     // + NEW2025
            | tokenIf__expression__body_for_true >> false_cond_block_without_else                                            // + NEW2025
            | tokenIf__expression__body_for_true >> body_for_false                                              // + NEW2025
            | tokenIf__expression >> block_statements_in_while_body_and_if_body                                 // + NEW2025
            | tokenFOR__cycle_counter_init__tokenTO_tokenDOWNTO__cycle_counter_last_value >> cycle_body/*__tokenSEMICOLON*/
            | tokenWhile__expression__statement_in_while_body_and_if_body____iteration_after_two >> tokenEnd__tokenWhile                                        // + NEW
            | tokenWhile__expression__statement_in_while_body_and_if_body >> tokenEnd__tokenWhile                                                            // + NEW
            | tokenWhile__expression >> tokenEnd__tokenWhile                                                                                      // + NEW
            | tokenREPEAT__statement____iteration_after_two >> tokenUNTIL__group_expression // +
            | tokenREPEAT__statement >> tokenUNTIL__group_expression                       // +
            | tokenREPEAT >> tokenUNTIL__group_expression                                 // + (!)
            | ident >> tokenCOLON                                                                                        // + 
            | tokenGOTO >> ident                                                                                            // + 
            | input__first_part >> input__second_part                         // + 
            | output__first_part >> output__second_part                 // +
            | block_statements____part1 >> tokenEndBLOCK // + NEW2025
            | tokenBEGINBLOCK >> tokenEndBLOCK; // + NEW2025
        statement____iteration_after_two = statement >> statement____iteration_after_two// + NEW
            | statement >> statement;  // + NEW
        //
        statement_in_while_body_and_if_body = ident >> rl_expression
            | lr_expression >> ident
            | tokenIf__expression__body_for_true__false_cond_block_without_else_iteration_after_one >> body_for_false        // + NEW2025
            | tokenIf__expression__body_for_true >> false_cond_block_without_else____iteration_after_two                     // + NEW2025
            | tokenIf__expression__body_for_true >> false_cond_block_without_else                                            // + NEW2025
            | tokenIf__expression__body_for_true >> body_for_false                                              // + NEW2025
            | tokenIf__expression >> block_statements_in_while_body_and_if_body                                 // + NEW2025
            | tokenFOR__cycle_counter_init__tokenTO_tokenDOWNTO__cycle_counter_last_value >> cycle_body/*__tokenSEMICOLON*/
            | tokenWhile__expression__statement_in_while_body_and_if_body____iteration_after_two >> tokenEnd__tokenWhile                                        // + NEW
            | tokenWhile__expression__statement_in_while_body_and_if_body >> tokenEnd__tokenWhile                                                            // + NEW
            | tokenWhile__expression >> tokenEnd__tokenWhile                                                                                      // + NEW
            | tokenREPEAT__statement____iteration_after_two >> tokenUNTIL__group_expression // +
            | tokenREPEAT__statement >> tokenUNTIL__group_expression                       // +
            | tokenREPEAT >> tokenUNTIL__group_expression                                 // + (!)
            | ident >> tokenCOLON                                                                                        // +
            | tokenGOTO >> ident                                                                                            // +
            | input__first_part >> input__second_part                         // +
            | output__first_part >> output__second_part                  // +
            | block_statements_in_while_body_and_if_body____part1 >> tokenEndBLOCK // + NEW2025
            | tokenBEGINBLOCK >> tokenEndBLOCK                                     // + NEW2025
            | tokenContinue >> tokenWhile                                                                                                        // + (!)
            | tokenEXIT >> tokenWhile;                                                                                                               // + (!)             
        ;
        statement_in_while_body_and_if_body____iteration_after_two = statement_in_while_body_and_if_body >> statement_in_while_body_and_if_body____iteration_after_two                          // + NEW
            | statement_in_while_body_and_if_body >> statement_in_while_body_and_if_body;                                                                                           // + NEW 
        //
        tokenNAME__program_name = tokenNAME >> program_name;  // + NEW
        tokenSEMICOLON__tokenStart = tokenSEMICOLON >> tokenStart;  // + NEW
        tokenDATA__declaration = tokenDATA >> declaration;  // + NEW
        tokenNAME__program_name__tokenSEMICOLON__tokenStart = tokenNAME__program_name >> tokenSEMICOLON__tokenStart;  // + NEW

        program____part1 = tokenNAME__program_name__tokenSEMICOLON__tokenStart >> tokenDATA__declaration  // + NEW
            | tokenNAME__program_name__tokenSEMICOLON__tokenStart >> tokenDATA;  // + NEW

        statement__tokenEnd = statement >> tokenEnd;  // + NEW
        statement____iteration_after_two__tokenEnd = statement____iteration_after_two >> tokenEnd;  // + NEW
        block_statements____part1 = tokenBEGINBLOCK >> statement____iteration_after_two
            | tokenBEGINBLOCK >> statement;  // + NEW2025
        block_statements = block_statements____part1 >> tokenEndBLOCK
            | tokenBEGINBLOCK >> tokenEndBLOCK;  // + NEW2025
        statement____iteration_after_two__tokenEnd = statement____iteration_after_two >> tokenEnd;  // + NEW
        block_statements_in_while_body_and_if_body____part1 = tokenBEGINBLOCK >> statement_in_while_body_and_if_body____iteration_after_two
            | tokenBEGINBLOCK >> statement_in_while_body_and_if_body;  // + NEW2025
        block_statements_in_while_body_and_if_body = block_statements_in_while_body_and_if_body____part1 >> tokenEndBLOCK
            | tokenBEGINBLOCK >> tokenEndBLOCK;  // + NEW2025
        program____part2 = tokenSEMICOLON >> statement____iteration_after_two__tokenEnd  // + NEW
            | tokenSEMICOLON >> statement__tokenEnd  // + NEW
            | tokenSEMICOLON >> tokenEnd;  // + NEW

        program = BOUNDARIES >> program____part1 >> program____part2;  // + NEW
        //
        digit = digit_0 | digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
        non_zero_digit = digit_1 | digit_2 | digit_3 | digit_4 | digit_5 | digit_6 | digit_7 | digit_8 | digit_9;
        unsigned_value = ((non_zero_digit >> *digit) | digit_0) >> BOUNDARIES;
        unsigned_value__non_terminal = SAME_RULE(unsigned_value);
        value = sign >> unsigned_value__non_terminal >> BOUNDARIES // + (!) A->BC
            | unsigned_value >> BOUNDARIES; // + (!) A->a
        letter_in_lower_case = a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z;
        letter_in_upper_case = A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z;
        ident = tokenUNDERSCORE >> letter_in_upper_case >> letter_in_upper_case >> letter_in_upper_case >> letter_in_upper_case >> letter_in_upper_case >> letter_in_upper_case >> letter_in_upper_case >> STRICT_BOUNDARIES;
        //label = letter_in_lower_case >> *letter_in_lower_case >> STRICT_BOUNDARIES; // !
        //
        sign = sign_plus           // + (!)
            | sign_minus;         // + (!)
        sign_plus = SAME_RULE(tokenPLUS); // '+' >> BOUNDARIES;
        sign_minus = SAME_RULE(tokenMINUS); // '-' >> BOUNDARIES;
        //
        digit_0 = '0';
        digit_1 = '1';
        digit_2 = '2';
        digit_3 = '3';
        digit_4 = '4';
        digit_5 = '5';
        digit_6 = '6';
        digit_7 = '7';
        digit_8 = '8';
        digit_9 = '9';
        //
        tokenCOLON = ":" >> BOUNDARIES;
        tokenGOTO = "GOTO" >> STRICT_BOUNDARIES;
        tokenInteger = "INTEGER16" >> STRICT_BOUNDARIES;
        tokenComma = "," >> BOUNDARIES;
        tokenNOT = "NOT" >> STRICT_BOUNDARIES;
        tokenAND = "AND" >> STRICT_BOUNDARIES;
        tokenOR = "OR" >> STRICT_BOUNDARIES;
        tokenEQUAL = "==" >> BOUNDARIES;
        tokenNOTEQUAL = "!=" >> BOUNDARIES;
        tokenLESSOREQUAL = "<=" >> BOUNDARIES;
        tokenGREATEROREQUAL = ">=" >> BOUNDARIES;
        tokenPLUS = "+" >> BOUNDARIES;
        tokenMINUS = "-" >> BOUNDARIES;
        tokenMul = "*" >> BOUNDARIES;
        tokenDiv = "DIV" >> STRICT_BOUNDARIES;
        tokenMod = "MOD" >> STRICT_BOUNDARIES;
        tokenGROUPEXPRESSIONBEGIN = "(" >> BOUNDARIES;
        tokenGROUPEXPRESSIONEND = ")" >> BOUNDARIES;
        tokenRLBIND = ":=" >> BOUNDARIES;
        tokenLRA = "=:" >> BOUNDARIES;
        tokenElse = "ELSE" >> STRICT_BOUNDARIES;
        tokenIf = "IF" >> STRICT_BOUNDARIES;
        tokenDO = "DO" >> STRICT_BOUNDARIES;
        tokenFOR = "FOR" >> STRICT_BOUNDARIES;
        tokenTO = "TO" >> STRICT_BOUNDARIES;
        tokenDOWNTO = "DOWNTO" >> STRICT_BOUNDARIES;
        tokenWhile = "WHILE" >> STRICT_BOUNDARIES;
        tokenContinue = "CONTINUE" >> STRICT_BOUNDARIES;
        tokenEXIT = "EXIT" >> STRICT_BOUNDARIES;
        tokenREPEAT = "REPEAT" >> STRICT_BOUNDARIES;
        tokenUNTIL = "UNTIL" >> STRICT_BOUNDARIES;
        tokenInput = "GET" >> STRICT_BOUNDARIES;
        tokenOutput = "PUT" >> STRICT_BOUNDARIES;
        tokenNAME = "NAME" >> STRICT_BOUNDARIES;
        tokenStart = "BODY" >> STRICT_BOUNDARIES;
        tokenDATA = "DATA" >> STRICT_BOUNDARIES;
        tokenBEGIN = "BEGIN" >> STRICT_BOUNDARIES;
        tokenEnd = "END" >> STRICT_BOUNDARIES;
        tokenBEGINBLOCK = "{" >> BOUNDARIES; // or STRICT_BOUNDARIES for keyword;
        tokenEndBLOCK = "}" >> BOUNDARIES;   // or STRICT_BOUNDARIES for keyword;
        tokenLEFTSQUAREBRACKETS = "[" >> BOUNDARIES; // or STRICT_BOUNDARIES for keyword;
        tokenRIGHTSQUAREBRACKETS = "]" >> BOUNDARIES; // or STRICT_BOUNDARIES for keyword;
        tokenSEMICOLON = ";" >> BOUNDARIES;
        // 
        //
        STRICT_BOUNDARIES = (BOUNDARY >> *(BOUNDARY)) | (!(qi::alpha | qi::char_("_")));
        BOUNDARIES = (BOUNDARY >> *(BOUNDARY) | NO_BOUNDARY);
        BOUNDARY = BOUNDARY_SPACE | BOUNDARY_TAB | BOUNDARY_CARRIAGE_RETURN | BOUNDARY_LINE_FEED | BOUNDARY_NULL;
        BOUNDARY_SPACE = " ";
        BOUNDARY_TAB = "\t";
        BOUNDARY_CARRIAGE_RETURN = "\r";
        BOUNDARY_LINE_FEED = "\n";
        BOUNDARY_NULL = "\0";
        NO_BOUNDARY = "";
        //
        tokenUNDERSCORE = "_";
        //
        A = "A";
        B = "B";
        C = "C";
        D = "D";
        E = "E";
        F = "F";
        G = "G";
        H = "H";
        I = "I";
        J = "J";
        K = "K";
        L = "L";
        M = "M";
        N = "N";
        O = "O";
        P = "P";
        Q = "Q";
        R = "R";
        S = "S";
        T = "T";
        U = "U";
        V = "V";
        W = "W";
        X = "X";
        Y = "Y";
        Z = "Z";
        //
        a = "a";
        b = "b";
        c = "c";
        d = "d";
        e = "e";
        f = "f";
        g = "g";
        h = "h";
        i = "i";
        j = "j";
        k = "k";
        l = "l";
        m = "m";
        n = "n";
        o = "o";
        p = "p";
        q = "q";
        r = "r";
        s = "s";
        t = "t";
        u = "u";
        v = "v";
        w = "w";
        x = "x";
        y = "y";
        z = "z";
        //
#ifdef DEBUG__IF_ERROR
        qi::on_error<qi::fail>(input,
            phx::ref(error_stream_) << "Error expecting " << qi::_4 << " here: \n"
            << phx::construct<std::string>(qi::_3, qi::_2) << "\n\n"
        );
#endif
    }
    std::ostringstream& error_stream_;

    qi::rule<Iterator>
        ADDON_RULES_LIST,
        labeled_point,
        goto_label,
        program_name,
        value_type,
        other_declaration_ident,
        declaration,
        unary_operator,
        binary_operator,
        binary_action,
        left_expression,
        expression,
        group_expression,
        bind_right_to_left,
        bind_left_to_right,
        //body_for_true,
        body_for_false,
        cond_block,
        cycle_counter,
        rl_expression,
        lr_expression,
        cycle_counter_init,
        //cycle_counter_last_value,
        cycle_body,
        forto_cycle,
        while_cycle,
        continue_while,
        exit_while,
        statement_in_while_body_and_if_body,
        block_statements_in_while_body_and_if_body,
        repeat_until_cycle_cond,
        repeat_until_cycle,
        input,
        output,
        statement,
        block_statements,
        program,
        //
        tokenCOLON, tokenGOTO, tokenInteger, tokenComma, tokenNOT, tokenAND, tokenOR, tokenEQUAL, tokenNOTEQUAL, tokenLESSOREQUAL,
        tokenGREATEROREQUAL, tokenPLUS, tokenMINUS, tokenMul, tokenDiv, tokenMod, tokenGROUPEXPRESSIONBEGIN, tokenGROUPEXPRESSIONEND, tokenRLBIND, tokenLRA,
        tokenElse, tokenIf, tokenDO, tokenFOR, tokenTO, tokenDOWNTO, tokenWhile, tokenContinue, tokenEXIT, tokenREPEAT, tokenUNTIL, tokenInput, tokenOutput, tokenNAME, tokenStart, tokenDATA, tokenBEGIN, tokenEnd, tokenBEGINBLOCK, tokenEndBLOCK, tokenLEFTSQUAREBRACKETS, tokenRIGHTSQUAREBRACKETS, tokenSEMICOLON,
        //
        STRICT_BOUNDARIES, BOUNDARIES, BOUNDARY, BOUNDARY_SPACE, BOUNDARY_TAB, BOUNDARY_CARRIAGE_RETURN, BOUNDARY_LINE_FEED, BOUNDARY_NULL,
        NO_BOUNDARY,
        //
        sign, sign_plus, sign_minus,
        digit_0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9,
        digit, non_zero_digit, value, unsigned_value,
        letter_in_upper_case, letter_in_lower_case, ident,
        //label,
        tokenUNDERSCORE,
        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
};

size_t loadSource(char** text, char* fileName) {
    if (!fileName) {
        printf("No input file name\r\n");
        return 0;
    }

    FILE* file = fopen(fileName, "rb");

    if (file == 0) {
        printf("File not loaded\r\n");
        return 0;
    }

    fseek(file, 0, 2);
    long fileSize_ = ftell(file);
    if (fileSize_ >= 8192) {
        printf("the file(%ld bytes) is larger than %d bytes\r\n", fileSize_, 8192);
        fclose(file);
        exit(2);

    }
    size_t fileSize = fileSize_;
    rewind(file);

    if (!text) {
        printf("Load source error\r\n");
        return 0;
    }
    *text = (char*)malloc(sizeof(char) * (fileSize + 1));
    if (*text == 0) {
        fputs("Memory error", (__acrt_iob_func(2)));
        fclose(file);
        exit(2);

    }

    size_t result = fread(*text, sizeof(char), fileSize, file);
    if (result != fileSize) {
        fputs("Reading error", (__acrt_iob_func(2)));
        fclose(file);
        exit(3);

    }
    (*text)[fileSize] = '\0';

    fclose(file);

    return fileSize;
}

#define MAX_LEXEM_SIZE 1024
int commentRemover(char* text, const char* openStrSpc, const char* closeStrSpc) {
    bool eofAlternativeCloseStrSpcType = false;
    bool explicitCloseStrSpc = true;
    if (!strcmp(closeStrSpc, "\n")) {
        eofAlternativeCloseStrSpcType = true;
        explicitCloseStrSpc = false;
    }

    unsigned int commentSpace = 0;

    unsigned int textLength = strlen(text);               // strnlen(text, MAX_TEXT_SIZE);
    unsigned int openStrSpcLength = strlen(openStrSpc);   // strnlen(openStrSpc, MAX_TEXT_SIZE);
    unsigned int closeStrSpcLength = strlen(closeStrSpc); // strnlen(closeStrSpc, MAX_TEXT_SIZE);
    if (!closeStrSpcLength) {
        return -1; // no set closeStrSpc
    }
    unsigned char oneLevelComment = 0;
    if (!strncmp(openStrSpc, closeStrSpc, MAX_LEXEM_SIZE)) {
        oneLevelComment = 1;
    }

    for (unsigned int index = 0; index < textLength; ++index) {
        if (!strncmp(text + index, closeStrSpc, closeStrSpcLength) && (explicitCloseStrSpc || commentSpace)) {
            if (commentSpace == 1 && explicitCloseStrSpc) {
                for (unsigned int index2 = 0; index2 < closeStrSpcLength; ++index2) {
                    text[index + index2] = ' ';
                }
            }
            else if (commentSpace == 1 && !explicitCloseStrSpc) {
                index += closeStrSpcLength - 1;
            }
            oneLevelComment ? commentSpace = !commentSpace : commentSpace = 0;
        }
        else if (!strncmp(text + index, openStrSpc, openStrSpcLength)) {
            oneLevelComment ? commentSpace = !commentSpace : commentSpace = 1;
        }

        if (commentSpace && text[index] != ' ' && text[index] != '\t' && text[index] != '\r' && text[index] != '\n') {
            text[index] = ' ';
        }

    }

    if (commentSpace && !eofAlternativeCloseStrSpcType) {
        return -1;
    }

    return 0;
}
#include <fstream>
int main(int argc, char* argv[]) {
    char* text_;
    char fileName[128] = DEFAULT_INPUT_FILE;
    char choice[2] = { fileName[0], fileName[1] };
    system("CLS");
    std::cout << "Enter file name(Enter \"" << choice[0] << "\" to use default \"" DEFAULT_INPUT_FILE "\"):";
    std::cin >> fileName;
    if (fileName[0] == choice[0] && fileName[1] == '\0') {
        fileName[1] = choice[1];
    }
    size_t sourceSize = loadSource(&text_, fileName);
    if (!sourceSize) {
#ifdef RERUN_MODE
        (void)getchar();
        printf("\nEnter 'y' to rerun program action(to pass action enter other key): ");
        char valueByGetChar = getchar();
        if (valueByGetChar == 'y' || valueByGetChar == 'Y') {
            system((std::string("\"") + argv[0] + "\"").c_str());
        }
        return 0;
#else
        printf("Press Enter to exit . . .");
        (void)getchar();
        return 0;
#endif
    }
    printf("Original source:\r\n");
    printf("-------------------------------------------------------------------\r\n");
    printf("%s\r\n", text_);
    printf("-------------------------------------------------------------------\r\n\r\n");
    int commentRemoverResult = commentRemover(text_, "#*", "*#");
    if (commentRemoverResult) {
        printf("Comment remover return %d\r\n", commentRemoverResult);
        printf("Press Enter to exit . . .");
        (void)getchar();
        return 0;
    }
    printf("Source after comment removing:\r\n");
    printf("-------------------------------------------------------------------\r\n");
    printf("%s\r\n", text_);
    printf("-------------------------------------------------------------------\r\n\r\n");

    std::string text(text_);

    typedef std::string     str_t;
    typedef str_t::iterator str_t_it;

    std::ostringstream error_stream;
    CW_GRAMMAR<str_t_it> cwg(error_stream);

    str_t_it begin = text.begin(), end = text.end();


    bool success = qi::parse(begin, end, cwg);

    if (!success) {
        std::cout << "\nParsing failed!\n";
        std::cout << "Error message: " << error_stream.str();
    }
    else if (begin != end) {
        std::cout << "\nUnknown fragment ofter successs parse at: \"" << str_t(begin, end) << "\"\n";
    }
    else {
        std::cout << "\nParsing success!\n";
    }

    free(text_);

    (void)getchar();

#ifdef RERUN_MODE
    printf("\nEnter 'y' to rerun program action(to pass action enter other key): ");
    char valueByGetChar = getchar();
    if (valueByGetChar == 'y' || valueByGetChar == 'Y') {
        system((std::string("\"") + argv[0] + "\"").c_str());
    }
#endif

    return 0;
}