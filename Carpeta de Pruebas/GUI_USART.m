function varargout = GUI_USART(varargin)
% GUI_USART MATLAB code for GUI_USART.fig
%      GUI_USART, by itself, creates a new GUI_USART or raises the existing
%      singleton*.
%
%      H = GUI_USART returns the handle to a new GUI_USART or the handle to
%      the existing singleton*.
%
%      GUI_USART('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_USART.M with the given input arguments.
%
%      GUI_USART('Property','Value',...) creates a new GUI_USART or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_USART_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_USART_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_USART

% Last Modified by GUIDE v2.5 17-Dec-2018 17:09:46

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_USART_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_USART_OutputFcn, ...
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


% --- Executes just before GUI_USART is made visible.
function GUI_USART_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_USART (see VARARGIN)

% Choose default command line output for GUI_USART
handles.output = hObject;
axes(handles.axes2)
xlim([-10 10])
ylim([-3.3 3.3])
grid
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI_USART wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_USART_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in ON.
function ON_Callback(hObject, eventdata, handles)
% hObject    handle to ON (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,1);


% --- Executes on button press in OFF.
function OFF_Callback(hObject, eventdata, handles)
% hObject    handle to OFF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,0);


% --- Executes on button press in conectar.
function conectar_Callback(hObject, eventdata, handles)
% hObject    handle to conectar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
delete(instrfind);
s = serial('COM3');% Change here accordingly..
set(s,'BaudRate',115200);
s.InputBufferSize = 2048;
s.OutputBufferSize = 2048;
fopen(s);

% --- Executes on button press in desconectar.
function desconectar_Callback(hObject, eventdata, handles)
% hObject    handle to desconectar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,0);
fclose(s);


% --- Executes on button press in Plot.
function Plot_Callback(hObject, eventdata, handles)
% hObject    handle to Plot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%set_param('DSPIC33F_Programa','SimulationCommand','start');
global s
%flushinput(s)
fwrite(s,0)
% fwrite(s,0)
global A;
global B;
%A = 0;
y = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1500, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end
%fwrite(s,0);

% --- Executes on button press in Save.
function Save_Callback(hObject, eventdata, handles)
% hObject    handle to Save (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
global B
save('Wels_data','B*')
%save('newstruct.mat','-struct','A');

function Ganancia_Callback(hObject, eventdata, handles)
% hObject    handle to Ganancia (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Ganancia as text
%        str2double(get(hObject,'String')) returns contents of Ganancia as a double
val = str2num(get(hObject,'String'));
%update both the model and the current string in the gain window.
if(val)
    assignin('base','a',val);
    %set_param('Prueba_de_gui_con_filtros','SimulationCommand','update');
else
    val = evalin('base','a');
    set(hObject,'String',num2str(val));
end

% --- Executes during object creation, after setting all properties.
function Ganancia_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Ganancia (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
%Comienza con un 1
set(hObject,'String','0');
evalin('base','a=0;');
%set_param('Prueba_de_gui_con_filtros','SimulationCommand','update');

% --- Executes on button press in Filtro1.
function Filtro1_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,1);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end
fwrite(s,0);



% --- Executes on button press in Filtro2.
function Filtro2_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,2);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end

% --- Executes on button press in Filtro3.
function Filtro3_Callback(hObject, ~, handles)
% hObject    handle to Filtro3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,3);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end


% --- Executes on button press in Filtro4.
function Filtro4_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,4);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s,1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end


% --- Executes on button press in Filtro5.
function Filtro5_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,5);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end

% --- Executes on button press in Filtro6.
function Filtro6_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,6);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.10);
    y = y + 1;
    %save('filed','A.')
end


% --- Executes on button press in Filtro7.
function Filtro7_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%flushinput(s)
%fwrite(s,0)
fwrite(s,7);
global A;
global B;
y = 0;
%A = 0;
% ii = 0;
% t = zeros(1e4,1);
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    %A = fscanf(string,'%o');
    %A(x) = fscanf(s,'%x');
    %A=str2num(A);
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    %save('filed','A.')
end


% --- Executes on button press in Filtro8.
function Filtro8_Callback(hObject, eventdata, handles)
% hObject    handle to Filtro8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s


% --- Executes on button press in Physionet.
function Physionet_Callback(hObject, eventdata, handles)
% hObject    handle to Physionet (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global sig_tmp1
cd C:\Users\Wels\Documents\MATLAB\ECG_Physionet\Hola
[old_path]=which('rdsamp'); if(~isempty(old_path)) rmpath(old_path(1:end-8)); end
wfdb_url='https://physionet.org/physiotools/matlab/wfdb-app-matlab/wfdb-app-toolbox-0-10-0.zip';
[filestr,status] = urlwrite(wfdb_url,'wfdb-app-toolbox-0-10-0.zip');
unzip('wfdb-app-toolbox-0-10-0.zip');
cd mcode
addpath(pwd)
savepath

[sig, Fs, tm] = rdsamp('mitdb/104', 1,1000);
%plot(tm,sig)
%tm_tmp = downsample(tm,9);
%sig_tmp= downsample(sig,9); 
sig_tmp= downsample(sig,1);
%plot(tm_tmp(1:1000),sig_tmp(1:1000))

%save('ECGRAW104.txt','sig_tmp','-ascii','-tabs');
%type('ECGRAW104.txt');
%sig_tmp=round(sig_tmp/max(sig_tmp(:))*(2^8-1));
%all = sprintf('%.0f,' , Data);
%all = all(1:end-1);
%csvwrite('ECGRAW_Sig.txt',sig_tmp1(1:500));
%type('ECGRAW_Sig.txt');
%sig_tmp=round(sig_tmp/max(sig_tmp(:))*(2^12-1));
%sig_tmp=round ((sig_tmp+1.5)*40);
sig_tmp=round ((sig_tmp+1)*200);
%plot(sig_tmp(1:1000));
%sig_tmp1=transpose(sig_tmp(1:100));
sig_tmp1=sig_tmp(1:end);


% --- Executes on button press in Mostrar.
function Mostrar_Callback(hObject, eventdata, handles)
% hObject    handle to Mostrar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,3);
y = 0;
while(y<1)
    %x = x + 1;
    A = fread(s, 1000, 'uint8');
    B = A;
    display(A);
    drawnow;
    plot(A,'r-')
    grid on;
    hold off;
    %save('Datos','B');
    %t(ii) - toc;
    pause(0.1);
    y = y + 1;
    ylim([-5 20])
    %save('filed','A.')
end


% --- Executes on button press in Mandar.
function Mandar_Callback(hObject, eventdata, handles)
% hObject    handle to Mandar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
global sig_tmp1
flushoutput(s);
%global dato
%flushinput(s);
fwrite(s,sig_tmp1);
