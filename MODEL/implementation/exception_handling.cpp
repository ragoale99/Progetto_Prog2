#include "../../MODEL/header/exception_handling.h"

void importDataXml(QXmlStreamReader& xmlInput, const string name, string& value) {
    xmlInput.readNextStartElement();
    if (xmlInput.name() != QString::fromStdString(name))
        throw importException();

    value = (xmlInput.readElementText()).toStdString();
}
