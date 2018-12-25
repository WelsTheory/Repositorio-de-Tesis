%% Instalar librerias de procesamiento de señal.
%cd C:\Users\walter\
%savepath
%pkg list
%pkg install signal
%pkg install statistics
%pkg install miscellaneous
%pkg load miscellaneous
%pkg load statistics
%pkg load signal
%% ________________________ Cargar physiotools ___________________________
cd C:\Users\Wels\Documents\MATLAB\ECG_Physionet\Hola
[old_path]=which('rdsamp'); if(~isempty(old_path)) rmpath(old_path(1:end-8)); end
wfdb_url='https://physionet.org/physiotools/matlab/wfdb-app-matlab/wfdb-app-toolbox-0-10-0.zip';
[filestr,status] = urlwrite(wfdb_url,'wfdb-app-toolbox-0-10-0.zip');
unzip('wfdb-app-toolbox-0-10-0.zip');
cd mcode
addpath(pwd)
savepath

% [old_path]=which('rdsamp'); if(~isempty(old_path)) rmpath(old_path(1:end-8)); end
% wfdb_url='https://physionet.org/physiotools/matlab/wfdb-app-matlab/wfdb-app-toolbox-0-10-0.zip';
% [filestr,status] = urlwrite(wfdb_url,'wfdb-app-toolbox-0-10-0.zip');
% unzip('wfdb-app-toolbox-0-10-0.zip');
% cd mcode
% addpath(pwd)
% savepath