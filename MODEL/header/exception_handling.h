#ifndef EXCEPTION_HANDLING
#define EXCEPTION_HANDLING

#include <QXmlStreamReader>
#include <string>
using std::string;

class importException {};

void importDataXml(QXmlStreamReader&, const string, string&);

#endif //EXCEPTION_HANDLING
