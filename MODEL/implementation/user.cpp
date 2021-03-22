#include "../header/user.h"

string user::getName() const{
	return name;
}

string user::getPassword() const{
	return password;
}

void user::setPassword(std::string pw){
    password = pw;
}

void user::exportXml(QXmlStreamWriter& xmlOutput) const {
    xmlOutput.writeStartElement(QString::fromStdString(getType()));             // scrive l'elemento inziale, ossia il tipo d'utente (es. <ADMIN>)

    xmlOutput.writeTextElement("nome", QString::fromStdString(name));           // scrive l'elemento "nome"
    xmlOutput.writeTextElement("password", QString::fromStdString(password));   // scrive l'elemento "password"

    xmlOutput.writeEndElement();                                                // chiude con l'elemento finale (es. </ADMIN>)
}

bool user::operator == (const user& u) const{
	return name == u.name && password == u.password;
}

bool user::operator != (const user& u) const{
	return name != u.name || password != u.password;
}
