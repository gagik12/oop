set PROGRAM="%~1"

rem %PROGRAM% input\map1.txt output\route1.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map2.txt output\route2.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map3.txt output\route3.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map4.txt output\route4.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map5.txt output\route5.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map6.txt output\route6.txt
rem if ERRORLEVEL 1 goto err

rem %PROGRAM% input\map7.txt output\route7.txt
rem if ERRORLEVEL 1 goto err

%PROGRAM% input\map8.txt output\route8.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1