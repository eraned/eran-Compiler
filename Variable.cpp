//
// Created by ise on 10/01/18.
//

#include "Variable.h"


const char* Variable::getType() {
    return m_type;
}

const char* Variable::getName() {
    return m_name;
}

Variable::Variable(char *type, char *name) {
    m_type = type;
    m_name = strdup(name);
    //m_name = name;
}

ostream &operator<<(ostream &out, const Variable &v) {
    out<<v.m_type;
    return out;
}

Variable::~Variable(void) {
    if (m_name)
        free(m_name);
}


