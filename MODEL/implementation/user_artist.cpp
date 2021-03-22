#include "../header/user_artist.h"

string user_artist::getLabel() const{
    return label;
}

void user_artist::setLabel(const string &value){
    label = value;
}

int user_artist::getSalary() const{
    return salary;
}

void user_artist::setSalary(int value){
    salary = value;
}


void user_artist::exportXml(QXmlStreamWriter& xmlOutput) const{
    //* this polimorfo, getLabel chiamata superpolimorfa
    xmlOutput.writeStartElement(QString::fromStdString(getType()));

    xmlOutput.writeTextElement("nome", QString::fromStdString(getName()));
    xmlOutput.writeTextElement("password", QString::fromStdString(getPassword()));
    xmlOutput.writeTextElement("label", QString::fromStdString(getLabel()));
    xmlOutput.writeTextElement("salary", QString::fromStdString(std::to_string(getSalary())));
    xmlOutput.writeEndElement();
}


