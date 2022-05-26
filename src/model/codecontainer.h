#ifndef CODECONTAINER_H
#define CODECONTAINER_H

#include <QFile>
#include <QString>
#include <QTextStream>

class CodeContainer
{
public:
    CodeContainer(){}
    CodeContainer(QString _path){
        path = _path;
        reloadCode();
    };
    void reloadCode(){
        codeLoaded = true;
        QFile fl(path);
        if (!fl.open(QIODevice::ReadOnly))
            return;
        code = fl.readAll();
    }
    void save(QString cpath = ""){
        if(cpath.isEmpty())
            cpath = path;

        QFile file(cpath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << code;
            file.close();;
        }
    };

    bool codeLoaded = false;
    QString code;
    QString path;
};

Q_DECLARE_METATYPE(CodeContainer*);

#endif // CODECONTAINER_H
