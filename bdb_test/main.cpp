#include <db_cxx.h>
#include <iostream>
#include <stdio.h>

void put(Db &db, float money, char *desc)
{
    Dbt key(&money, sizeof(float));
    Dbt data(desc, strlen(desc) + 1);

    int ret = db.put(NULL, &key, &data, DB_NOOVERWRITE);
    if (ret == DB_KEYEXIST)
    {
        db.err(ret, "Put failed because key %f already exists",
                        money);
    }
}

char* get(Db &db, float money) 
{
    Dbt key, data;
    char *desc = (char *)malloc(256);
    key.set_data(&money);
    key.set_size(sizeof(float));

    data.set_data(desc);
    data.set_ulen(256);
    data.set_flags(DB_DBT_USERMEM);
    db.get(NULL, &key, &data, 0);
    return desc;
}
int main()
{
	Db db(NULL, 0);               // Instantiate the Db object

	u_int32_t oFlags = DB_CREATE; // Open flags;

	try {
		// Open the database
		db.open(NULL,                // Transaction pointer 
			"my_db.db",          // Database file name 
			"main",                // Optional logical database name
			DB_BTREE,            // Database access method
			oFlags,              // Open flags
			0);                  // File mode (using defaults)
								 // DbException is not subclassed from std::exception, so
								 // need to catch both of these.
	}
	catch (DbException &e) {
		// Error handling code goes here  
		
	}
	catch (std::exception &e) {
		// Error handling code goes here
	}

    char *description = "Grocery bill.";
    float money = 122.45;

    put(db, money, description);
    char *desc = get(db, money);    
    printf("%f -> %s\n", money, desc);

    try {
		// Close the database
		db.close(0);
		// DbException is not subclassed from std::exception, so
		// need to catch both of these.
	}
	catch (DbException &e) {
		// Error handling code goes here    
	}
	catch (std::exception &e) {
		// Error handling code goes here
	}
}