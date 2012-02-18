#ifndef _NFO_SOURCECODE_H_
#define _NFO_SOURCECODE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>

#include <nepomuk/simpleresource.h>

#include "nfo/plaintextdocument.h"

namespace Nepomuk {
namespace NFO {
/**
 * Code in a compilable or interpreted programming language. 
 */
class SourceCode : public virtual NFO::PlainTextDocument
{
public:
    SourceCode(const QUrl& uri = QUrl())
      : SimpleResource(uri), NIE::InformationElement(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::Document(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::TextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::PlainTextDocument(uri, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)) {
    }

    SourceCode(const SimpleResource& res)
      : SimpleResource(res), NIE::InformationElement(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::Document(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::TextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)), NFO::PlainTextDocument(res, QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode)) {
    }

    SourceCode& operator=(const SimpleResource& res) {
        SimpleResource::operator=(res);
        addType(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode", QUrl::StrictMode));
        return *this;
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    QStringList definesClasses() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    void setDefinesClasses(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass. 
     * Name of a class defined in the source code file. 
     */
    void addDefinesClass(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesClass", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    QStringList definesGlobalVariables() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    void setDefinesGlobalVariables(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable. 
     * Name of a global variable defined within the source code file. 
     */
    void addDefinesGlobalVariable(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesGlobalVariable", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    QStringList programmingLanguages() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    void setProgrammingLanguages(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage. 
     * Indicates the name of the programming language this source 
     * code file is written in. Examples might include 'C', 'C++', 
     * 'Java' etc. 
     */
    void addProgrammingLanguage(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#programmingLanguage", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    qint64 commentCharacterCount() const {
        qint64 value;
        if(contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode)))
            value = property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    void setCommentCharacterCount(const qint64& value) {
        QVariantList values;
        values << value;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount. 
     * The amount of character in comments i.e. characters ignored 
     * by the compiler/interpreter. 
     */
    void addCommentCharacterCount(const qint64& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#commentCharacterCount", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    QStringList definesFunctions() const {
        QStringList value;
        foreach(const QVariant& v, property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    void setDefinesFunctions(const QStringList& value) {
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction. 
     * A name of a function/method defined in the given source code 
     * file. 
     */
    void addDefinesFunction(const QString& value) {
        addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#definesFunction", QUrl::StrictMode), value);
    }

protected:
    SourceCode(const QUrl& uri, const QUrl& type)      : SimpleResource(uri), NIE::InformationElement(uri, type), NFO::Document(uri, type), NFO::TextDocument(uri, type), NFO::PlainTextDocument(uri, type) {
    }
    SourceCode(const SimpleResource& res, const QUrl& type)
      : SimpleResource(res), NIE::InformationElement(res, type), NFO::Document(res, type), NFO::TextDocument(res, type), NFO::PlainTextDocument(res, type) {
    }
};
}
}

#endif
