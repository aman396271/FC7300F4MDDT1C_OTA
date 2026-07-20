@echo off
cd /d "%~dp0.."
python -m Tools.ota_host.package_gui
if errorlevel 1 pause
