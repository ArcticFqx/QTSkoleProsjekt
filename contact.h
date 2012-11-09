#ifndef CONTACT_H
#define CONTACT_H

#include <QString>


class Contact {

public:
    Contact();
    Contact(QString);

    QString getContactName() { return contactName; }

private:
    QString contactName;

};

#endif // CONTACT_H
