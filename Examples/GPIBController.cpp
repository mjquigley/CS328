class GPIBController
{
public:
	void insert(char* dev_name, int address);
	void send(int address, char* command);
	void send(int address, float voltage);
	float recieve(int address);
};
//Notice again: no state vars


class Acme130	//voltage supply
{
public:
	Acme130(GPIBController controller, int address);
	void set(float volts);
	float min();
	float max();
private:
	GPIBController my_controller;
	int gpib_address;
}

Acme130::Acme130(GPIBController controller, int address)
{
	my_controller = controller;
	gpib_address = address;
	my_controller.insert("Acme130", gpib_address);
}

class GPIBInstrument{
public:
	virtual void send(const char* c) = 0;
	virtual void send(float f) = 0;
	virtual float receive() = 0;
	virtual ~GPIBInstrument(){}
};
//this is a generalized GPIBInstrument class so we can use Acme130
//objects, volton59 objects and the voltymetrics objects through 
//pointers or references to the GPIBInstrument class.

class Acme130 : public VoltageSupply, public GPIBInstrument{
public:
	Acme130(...);
	//vs interface
	virtual void set(...);
	//etc
	//GPIBInstrument interface
	virtual void send(...);
	//etc
};

class GPIBController{
public:
	virtual void insert(...) =0;
	virtual void send(...) =0;
	virtual void send(...) =0;
	virtual float receive() =0;
	virtual ~GPIBController(){} 
};

class GPIB : public GPIBController{
public:
	virtual void insert(...);
	virtual void send(...);
	//etc
};

//...and the generalized acme130

class Acme130 : public VS, public GPIBInstrument{
public:
	Acme130(GPIBController& controller, ...);
	//...etc
private:
	GPIBController& my_controller;
	//...etc
};

class IVTester{
public:
	IVTester(VoltageSupply& vs, VoltMeter& vm): supply(vs), meter(vm){}
	double current();
private:
	VoltageSupply& supply;
	VoltMeter& meter;
}