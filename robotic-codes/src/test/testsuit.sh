#!/bin/bash

g++ test_lstr.cpp >& test_lstr.txt

if [ -s  test_lstr.txt ]
then
	echo test_lstr.txt created 
else
	./a.out < input_lstr.txt >> test_lstr.txt
	echo test_lstr.txt created

fi
g++ test_ucase.cpp >& test_ucase.txt
if [ -s test_ucase.txt ]
then
	echo test_ucase.txt created
else
	./a.out < input_ucase.txt >> test_ucase.txt
	echo test_ucase.txt created
fi
g++ test_btrim.cpp >& test_btrim.txt
if [ -s test_btrim.txt ]
then
	echo test_btrim.txt created
else
	./a.out < input_btrim.txt >> test_btrim.txt
	echo test_btrim.txt created
fi

g++ test_cutomarray.cpp >& test_customarray.txt
if [ -s test_customarray.txt ]
then
	echo test_customarray.txt created
else
	./a.out < input_customarray.txt >> test_customarray.txt
	echo test_customarray.txt created
fi

g++ test_hexnum.cpp >& test_hexnum.txt
if [ -s test_hexnum.txt ]
then
	echo test_hexnum.txt created
else
	./a.out < input_hexnum.txt >> test_hexnum.txt
	echo test_hexnum.txt created 
fi

g++ test_hexb.cpp >& test_hexb.txt
if [ -s test_hexb.txt ]
then
	echo test_hexb.txt created
else
	./a.out < input_hexb.txt >> test_hexb.txt
	echo test_hexb.txt created
fi

g++ test_hex.cpp >& test_hex.txt
if [ -s test_hex.txt ]
then
	echo test_hex.txt created
else
	./a.out < input_hex.txt >> test_hex.txt
	echo test_hex.txt created
fi

g++ test_valuer.cpp >& test_valuer.txt
if [ -s test_valuer.txt ]
then
	echo test_valuer.txt created
else
	./a.out < input_valuer.txt >> test_valuer.txt
	echo test_valuer.txt created
fi

g++ test_value.cpp >& test_value.txt
if [ -s test_value.txt ]
then
	echo test_value.txt created
else
	./a.out < input_value.txt >> test_value.txt
	echo test_value.txt created
fi

g++ test_cstrr.cpp >& test_cstrr.txt
if [ -s test_cstrr.txt ]
then
	echo test_cstrr.txt created
else
	./a.out < input_cstrr.txt >> test_cstrr.txt
	echo test_cstrr.txt created
fi

g++ test_cstr.cpp >& test_cstr.txt
if [ -s test_cstr.txt ]
then
        echo test_cstr.txt created
else
        ./a.out < input_cstr.txt >> test_cstr.txt
        echo test_cstr.txt created
fi

g++ test_zeropad.cpp >& test_zeropad.txt
if [ -s test_zeropad.txt ]
then
        echo test_zeropad.txt created
else
        ./a.out < input_zeropad.txt >> test_zeropad.txt
        echo test_zeropad.txt created
fi

g++ test_zeropads.cpp >& test_zeropads.txt
if [ -s test_zeropads.txt ]
then
        echo test_zeropads.txt created
else
        ./a.out < input_zeropads.txt >> test_zeropads.txt
        echo test_zeropads.txt created
fi

g++ test_addfront.cpp >& test_addfront.txt
if [ -s test_addfront.txt ]
then
        echo test_addfront.txt created
else
        ./a.out < input_addfront.txt >> test_addfront.txt
        echo test_addfront.txt created
fi

g++ test_addrear.cpp >& test_addrear.txt
if [ -s test_addrear.txt ]
then
	echo test_addrear.txt created
else
	./a.out < input_addrear.txt >> test_addrear.txt
	echo test_addrear.txt created
fi

g++ test_lcase.cpp >& test_lcase.txt
if [ -s test_lcase.txt ]
then
	echo test_lcase.txt created
else
	./a.out < input_lcase.txt >> test_lcase.txt
	echo test_lcase.txt created
fi

g++ test_space.cpp >& test_space.txt
if [ -s test_space.txt ]
then
	echo test_space.txt created
else
	./a.out < input_space.txt >> test_space.txt
	echo test_space.txt created
fi

g++ test_repchar.cpp >& test_repchar.txt
if [ -s test_repchar.txt ]
then
	echo test_repchar.txt created
else
	./a.out < input_repchar.txt >> test_repchar.txt
	echo test_repchar.txt created
fi

g++ test_rstr.cpp >& test_rstr.txt
if [ -s test_rstr.txt ]
then
	echo test_rstr.txt created
else
	./a.out < input_rstr.txt >> test_rstr.txt
	echo test_rstr.txt created
fi

g++ test_rol.cpp >& test_rol.txt
if [ -s test_rol.txt ]
then
	echo test_rol.txt created
else
	./a.out < input_rol.txt >> test_rol.txt
	echo test_rol.txt created
fi

g++ test_ror.cpp >& test_ror.txt
if [ -s test_ror.txt ]
then
        echo test_ror.txt created
else
        ./a.out < input_ror.txt >> test_ror.txt
        echo test_ror.txt created
fi

g++ test_sal.cpp >& test_sal.txt
if [ -s test_sal.txt ]
then
        echo test_sal.txt created
else
        ./a.out < input_sal.txt >> test_sal.txt
        echo test_sal.txt created
fi

g++ test_sar.cpp >& test_sar.txt
if [ -s test_sar.txt ]
then
        echo test_sar.txt created
else
        ./a.out < input_sar.txt >> test_sar.txt
        echo test_sar.txt created
fi

g++ test_robotcolor.cpp >& test_robotcolor.txt
if [ -s test_robotcolor.txt ]
then
	echo test_robotcolor.txt created
else
	./a.out < input_robotcolor.txt >> test_robotcolor.txt
	echo test_robotcolor.txt created
fi

g++ test_hex2int.cpp >& test_hex2int.txt
if [ -s test_hex2int.txt ]
then
	echo test_hex2int.txt created
else
	./a.out < input_hex2int.txt >> test_hex2int.txt
	echo test_hex2int.txt created
fi

g++ test_str2int.cpp >& test_str2int.txt
if [ -s test_str2int.txt ]
then 
        echo test_str2int.txt created
else 
        ./a.out < input_str2int.txt >> test_str2int.txt
        echo test_str2int.txt created
fi 

g++ test_distance.cpp >& test_distance.txt
if [ -s test_distance.txt ]
then
	echo test_distance.txt created
else
	./a.out < input_distance.txt >> test_distance.txt
	echo test_distance.txt created
fi

g++ test_findangle.cpp >& test_findangle.txt
if [ -s test_findangle.txt ]
then
        echo test_findangle.txt created
else
        ./a.out < input_findangle.txt >> test_findangle.txt
        echo test_findangle.txt created
fi

g++ test_findanglei.cpp >& test_findanglei.txt
if [ -s test_findanglei.txt ]
then
        echo test_findanglei.txt created
else
        ./a.out < input_findanglei.txt >> test_findanglei.txt
        echo test_findanglei.txt created
fi

g++ test_bin.cpp >& test_bin.txt
if [ -s test_bin.txt ]
then
	echo test_bin.txt created
else
	./a.out < input_bin.txt >> test_bin.txt
	echo test_bin.txt created
fi

g++ test_decimal.cpp >& test_decimal.txt
if [ -s test_decimal.txt ]
then
        echo test_decimal.txt created
else
        ./a.out < input_decimal.txt >> test_decimal.txt
        echo test_decimal.txt created
fi

g++ test_coltextxy.cpp >& test_coltextxy.txt
if [ -s test_coltextxy.txt ]
then
        echo test_coltextxy.txt created
else
        ./a.out < input_coltextxy.txt >> test_coltextxy.txt
        echo test_coltextxy.txt created
fi

g++ test_flushkey.cpp >& test_flushkey.txt
if [ -s test_flushkey.txt ]
then
        echo test_flushkey.txt created
else
        ./a.out < input_flushkey.txt >> test_flushkey.txt
        echo test_flushkey.txt created
fi

