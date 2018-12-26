function varargout = Tesis_Interfaz(varargin)
% TESIS_INTERFAZ MATLAB code for Tesis_Interfaz.fig
%      TESIS_INTERFAZ, by itself, creates a new TESIS_INTERFAZ or raises the existing
%      singleton*.
%
%      H = TESIS_INTERFAZ returns the handle to a new TESIS_INTERFAZ or the handle to
%      the existing singleton*.
%
%      TESIS_INTERFAZ('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TESIS_INTERFAZ.M with the given input arguments.
%
%      TESIS_INTERFAZ('Property','Value',...) creates a new TESIS_INTERFAZ or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Tesis_Interfaz_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Tesis_Interfaz_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Tesis_Interfaz

% Last Modified by GUIDE v2.5 25-Dec-2018 19:35:12

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Tesis_Interfaz_OpeningFcn, ...
                   'gui_OutputFcn',  @Tesis_Interfaz_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Tesis_Interfaz is made visible.
function Tesis_Interfaz_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Tesis_Interfaz (see VARARGIN)

% Choose default command line output for Tesis_Interfaz
handles.output = hObject;
axes(handles.axes1)
xlim([0 20])
ylim([0 20])
grid
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Tesis_Interfaz wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Tesis_Interfaz_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Conectar.
function Conectar_Callback(hObject, eventdata, handles)
% hObject    handle to Conectar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
delete(instrfind);
s = serial('COM6');% Change here accordingly..
set(s,'BaudRate',115200);
s.InputBufferSize = 2048;
s.OutputBufferSize = 2048;
fopen(s);
Mensaje = 'Sistema Conectado';
set(handles.Titulo,'String',Mensaje);




% --- Executes on button press in Desconectar.
function Desconectar_Callback(hObject, eventdata, handles)
% hObject    handle to Desconectar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,0);
Mensaje = 'Sistema Desconectado';
set(handles.Titulo,'String',Mensaje);
fclose(s);


% --- Executes on button press in On.
function On_Callback(hObject, eventdata, handles)
% hObject    handle to On (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,1);


% --- Executes on button press in Off.
function Off_Callback(hObject, eventdata, handles)
% hObject    handle to Off (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,0);


% --- Executes on button press in Plot.
function Plot_Callback(hObject, eventdata, handles)
% hObject    handle to Plot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,0);
y = 0;
Mensaje = 'Obteniendo datos ECG Raw';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end

% --- Executes on button press in Filtro1.
function Filtro1_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,1);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 1';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end


% --- Executes on button press in Filtro2.
function Filtro2_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,2);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 2';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end


% --- Executes on button press in Filtro3.
function Filtro3_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,3);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 3';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end

% --- Executes on button press in Filtro4.
function Filtro4_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,4);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 4';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end
Mensaje = 'Data Filtrada';
set(handles.Titulo,'String',Mensaje);


% --- Executes on button press in Filtro5.
function Filtro5_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,5);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 5';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end


% --- Executes on button press in Filtro6.
function Filtro6_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,6);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 6';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end

% --- Executes on button press in Filtro7.
function Filtro7_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s, global A, global Data
flushinput(s);
fwrite(s,7);
y = 0;
Mensaje = 'Obteniendo datos de Filtro 7';
set(handles.Titulo,'String',Mensaje);
while(y<1)
    A = fread(s, 1000, 'uint8');
    Data = A;
    %display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    pause(0.1);
    y = y + 1;
    ylim([0 inf])
end


% --- Executes on button press in Save.
function Save_Callback(hObject, eventdata, handles)
% hObject    handle to Save (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global Data
Texto = get(handles.Name,'String');
save(Texto, 'Data');
Mensaje = 'Data Guardada!';
set(handles.Titulo,'String',Mensaje);




function Name_Callback(hObject, eventdata, handles)
% hObject    handle to Name (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)S
% Hints: get(hObject,'String') returns contents of Name as text
%        str2double(get(hObject,'String')) returns contents of Name as a double


% --- Executes during object creation, after setting all properties.
function Name_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Name (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Physionet.
function Physionet_Callback(hObject, eventdata, handles)
% hObject    handle to Physionet (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global sig_tmp1
Signal = get(handles.Texto2,'String');
cd E:\Repositorio-de-Tesis\Physionet_Datos
[old_path]=which('rdsamp'); if(~isempty(old_path)) rmpath(old_path(1:end-8)); end
wfdb_url='https://physionet.org/physiotools/matlab/wfdb-app-matlab/wfdb-app-toolbox-0-10-0.zip';
[filestr,status] = urlwrite(wfdb_url,'wfdb-app-toolbox-0-10-0.zip');
unzip('wfdb-app-toolbox-0-10-0.zip');
cd mcode
addpath(pwd)
savepath

[sig, Fs, tm] = rdsamp(Signal, 1,1000);
sig_tmp= downsample(sig,1);
sig_tmp=round ((sig_tmp+1)*200);
sig_tmp1=sig_tmp(1:end);

pause(1);
Mensaje = 'Se generó la data del Physionet';
set(handles.Titulo,'String',Mensaje);
cd E:\Repositorio-de-Tesis


% --- Executes on button press in DataPhysionet.
function DataPhysionet_Callback(hObject, eventdata, handles)
% hObject    handle to DataPhysionet (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
global sig_tmp1
fwrite(s,sig_tmp1);



function Texto2_Callback(hObject, eventdata, handles)
% hObject    handle to Texto2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Texto2 as text
%        str2double(get(hObject,'String')) returns contents of Texto2 as a double


% --- Executes during object creation, after setting all properties.
function Texto2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Texto2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


