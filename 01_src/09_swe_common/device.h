//
// Created by mirko on 19.02.17.
//

#ifndef LABOR_SWE_2_DEVICE_H
#define LABOR_SWE_2_DEVICE_H

#include <string>

class IDevice {
public:;

    virtual void mPlus ()=0;

    virtual void mMinus ()=0;

    virtual void mZustandsausgabe ()=0;

protected:
    int         mInternerZustand;
    std::string mDeviceName;
};

// für Kinder zugreifbar
class CFernbedienung : public IDevice {
public:
    enum Mode {
        Kaffeemaschine, Radio, Heizung
    };

    CFernbedienung (IDevice *Dev1Ptr, IDevice *Dev2Ptr, IDevice *Dev3Ptr);

// hier werden die Adressend er Device-Objekte übergeben
    virtual void mPlus ();

    virtual void mMinus ();

    virtual void mZustandsausgabe ();

    void mModeChange ();

private:
    IDevice *mDevPtr;
// dieser Zeiger zeigt auf das jeweils per Mode-Taste selektierte Objekt.
// Damit können dann direkt dessen Funktionen aufgehoben werden.
    IDevice *mDev1Ptr;
// hier werden die Adressen der Device-Objekte aufgehoben
    IDevice *mDev2Ptr;
    IDevice *mDev3Ptr;
    Mode    mMode;
// hier wird der Status der Mode-Taste aufgehoben
};

class CKaffemaschine : public IDevice { ;
public:
    CKaffemaschine (int i);

    virtual void mPlus ();

    virtual void mMinus ();

    virtual void mZustandsausgabe ();
};

class CRadio : public IDevice {
public:
    CRadio (int i);

    virtual void mPlus ();

    virtual void mMinus ();

    virtual void mZustandsausgabe ();
};

class CHeizung : public IDevice {
public:
    CHeizung (int i);

    virtual void mPlus ();

    virtual void mMinus ();

    virtual void mZustandsausgabe ();
};

#endif //LABOR_SWE_2_DEVICE_H
