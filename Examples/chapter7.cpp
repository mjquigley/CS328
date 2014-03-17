using namespace std;

class trace{
public:
	Trace(const char* name);
	~Trace();
private:
	enum {max = 100};	//max num of objects traced
	static char existing_objs[1+max];	//L-Live, D-Dead
	static int total_created;
	int instance;
	char var_name[21];
};

int Trace::total_created = 0;
char Trace:existing_objs[1+max] = "";

Trace::Trace(const char* name):instance(total_created++){
	strncpy(var_name, name, 20);
	var_name[20] = '\0';
	if (total_created <= max){
		existing_objs[total_created-1] = 'L';
		existing_objs[total_created] = '\0';
		cout << existing_objs << " Trace created for " << var_name << endl;
	}
}

Trace::~Trace(){
	if (instance < max){
		existing_objs[instance] = 'D';
		cout << existing_objs << " Trace destroyed for " << var_name << endl;
	}
}

int main(){
	cout<<"---start main---"<<endl;
	trace a1("a1");
	for (int i = 1; 1 <= 2; i++){
		cout << "--- start loop i = "<<i<<endl;
		trace a2("a2");
		if (i == 2)
			trace a3("a3")
	}
	cout << "--- loop done ---" <<endl;
	trace a4("a4");
	cout << "--- end main ---" << endl;
	return 0;
}