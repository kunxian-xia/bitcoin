project(bitcoin)

# this project's prerequisites are
#  1. boost
#  2. openssl
#  3. berkeley db
#  4. wxWidgets

add_executable(
    bitcoin.exe
	net.cpp
	db.cpp
    main.cpp
)

target_include_directories(
	bitcoin.exe
	net.h
	db.h
)