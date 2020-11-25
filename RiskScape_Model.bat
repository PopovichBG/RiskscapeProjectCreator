REM Sample batch file to run RiskScape model 
REM Note that there are many possible ways of constructing a batch script
REM This is only one possibility
@echo on
cd %userprofile%\RiskscapeProjects\
set "Riskscape=C:\Riskscape\bin\Riskscape.bat --home=C:\MyHomeDirectory"
call %Riskscape% model run default -p asset=SampleAssetBookmark -p hazard=SampleHazardBookmark -p function=A_Sample_Function -f csv -o -
pause