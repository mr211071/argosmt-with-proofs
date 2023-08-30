/****************************************************************************
argosmt (an open source SMT solver)
Copyright (C) 2023 Milan Bankovic (milan@matf.bg.ac.rs)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public Lcense
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
***************************************************************************/
#ifndef _PROOFS_H
#define _PROOFS_H

#include "expression_library/expression_library.hpp"
#include "clause.hpp"

class axiom_true : public proof_node{
    private:
        std::string value;

    public:
        axiom_true(){
            value = "true+";
        }

        void print_proof(std::ostream & ostr){
            ostr << value;
        }

        bool check_proof(){
            return true;
        }
        
        ~axiom_true(){}
};

class axiom_false : public proof_node{
    private:
        std::string value;

    public:
        axiom_false(){
            value = "false-";
        }

        void print_proof(std::ostream & ostr){
            ostr << value;
        }

        bool check_proof(){
            return true;
        }
        
        ~axiom_false(){}
};

class proof_assume : public proof_node{
    private:
        expression expr;

    public:
        proof_assume(expression && _expr){
            expr = std::move(_expr); // ??
        }

        void print_proof(std::ostream & ostr){
            ostr << "(assume " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_and_intro : public proof_node{
    private:
        expression expr;

    public:
        axiom_and_intro(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(and+ " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_and_elim : public proof_node{
    private:
        expression expr;
        unsigned i;

    public:
        axiom_and_elim(expression && _expr, unsigned ord){
            expr = _expr;
            i = ord;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(and- " << i << " " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_or_intro : public proof_node{
    private:
        expression expr;
        unsigned i;

    public:
        axiom_or_intro(expression && _expr, unsigned ord){
            expr = _expr;
            i = ord;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(or+ " << i << " " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_or_elim : public proof_node{
    private:
        expression expr;

    public:
        axiom_or_elim(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(or- " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_impl_intro : public proof_node{
    private:
        expression expr;
        unsigned i;

    public:
        axiom_impl_intro(expression && _expr, unsigned ord){
            expr = _expr;
            i = ord;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=>+ " << i << " " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_impl_elim : public proof_node{
    private:
        expression expr;

    public:
        axiom_impl_elim(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=>- " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_eq1_intro : public proof_node{
    private:
        expression expr;

    public:
        axiom_eq1_intro(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=+1 " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_eq1_elim : public proof_node{
    private:
        expression expr;

    public:
        axiom_eq1_elim(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=-1 " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_eq2_intro : public proof_node{
    private:
        expression expr;

    public:
        axiom_eq2_intro(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=+2 " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_eq2_elim : public proof_node{
    private:
        expression expr;

    public:
        axiom_eq2_elim(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(=-2 " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_xor_intro : public proof_node{
    private:
        expression_vector l1, l2, l3;

    public:
        axiom_xor_intro(expression_vector & _l1, expression_vector & _l2, expression_vector & _l3){
            for(auto & e : _l1)
                l1.push_back(e);

            for(auto & e : _l2)
                l2.push_back(e);

            for(auto & e : _l3)
                l3.push_back(e);
        }

        void print_proof(std::ostream & ostr){
            ostr << "(xor+ ()";
            
            for(auto & e : l1)
                ostr << " " << e;

            ostr << ") (";

            for(auto & e : l2)
                ostr << " " << e;

            ostr << ") (";

            for(auto & e : l3)
                ostr << " " << e;
            
            ostr << "))";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_xor_elim : public proof_node{
    private:
        expression_vector l1, l2, l3;

    public:
        axiom_xor_elim(expression_vector & _l1, expression_vector & _l2, expression_vector & _l3){
            for(auto & e : _l1)
                l1.push_back(e);

            for(auto & e : _l2)
                l2.push_back(e);

            for(auto & e : _l3)
                l3.push_back(e);
        }

        void print_proof(std::ostream & ostr){
            ostr << "(xor- ()";
            
            for(auto & e : l1)
                ostr << " " << e;

            ostr << ") (";

            for(auto & e : l2)
                ostr << " " << e;

            ostr << ") (";

            for(auto & e : l3)
                ostr << " " << e;
            
            ostr << "))";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_refl : public proof_node{
    private:
        expression expr;

    public:
        axiom_refl(expression && _expr){
            expr = _expr;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(refl " << expr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_symm : public proof_node{
    private:
        expression left, right;

    public:
        axiom_symm(expression && l, expression && r){
            left = l;
            right = r;
        }

        void print_proof(std::ostream & ostr){
            ostr << "(symm " << left << " " << right << ")";
        }

        bool check_proof(){
            return true;
        }
};

class axiom_trans : public proof_node{
    private:
        expression_vector exprs;

    public:
        axiom_trans(expression_vector & _exprs){
            for(auto & e : _exprs)
                exprs.push_back(e);
        }

        void print_proof(std::ostream & ostr){
            ostr << "(trans";
            
            for(auto & e : exprs) 
                ostr << " " << e;
                
            ostr << ")";
        }

        bool check_proof(){
            return true;
        }
};

class resolution_proof : public proof_node{
    private:
        expression lit;
        proof left;
        proof right;
        
    public:
        resolution_proof(expression && _expr, proof l, proof r){
            lit = _expr;
            left = l;
            right = r;
        }
        
        void print_proof(std::ostream & ostr){
            ostr << "(res ";
            
            ostr << lit << " ";
            
            left->print_proof(ostr);
            
            ostr << " ";
            
            right->print_proof(ostr);
                
            ostr << ")";
        }

        bool check_proof(){
            return true;
        }
};

#endif // _PROOFS_H
