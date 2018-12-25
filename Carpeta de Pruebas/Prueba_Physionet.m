function varargout = Prueba_Physionet(varargin)
% PRUEBA_PHYSIONET MATLAB code for Prueba_Physionet.fig
%      PRUEBA_PHYSIONET, by itself, creates a new PRUEBA_PHYSIONET or raises the existing
%      singleton*.
%
%      H = PRUEBA_PHYSIONET returns the handle to a new PRUEBA_PHYSIONET or the handle to
%      the existing singleton*.
%
%      PRUEBA_PHYSIONET('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PRUEBA_PHYSIONET.M with the given input arguments.
%
%      PRUEBA_PHYSIONET('Property','Value',...) creates a new PRUEBA_PHYSIONET or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Prueba_Physionet_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Prueba_Physionet_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Prueba_Physionet

% Last Modified by GUIDE v2.5 19-Dec-2018 17:13:42

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Prueba_Physionet_OpeningFcn, ...
                   'gui_OutputFcn',  @Prueba_Physionet_OutputFcn, ...
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


% --- Executes just before Prueba_Physionet is made visible.
function Prueba_Physionet_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Prueba_Physionet (see VARARGIN)

% Choose default command line output for Prueba_Physionet
handles.output = hObject;
axes(handles.axes1)
xlim([-10 20])
ylim([-3.3 20])
grid
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Prueba_Physionet wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Prueba_Physionet_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
global sig_tmp1
fwrite(s,sig_tmp1);


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
delete(instrfind);
s = serial('COM3');% Change here accordingly..
set(s,'BaudRate',115200);
s.InputBufferSize = 2048;
s.OutputBufferSize = 4096;
fopen(s);


% --- Executes on button press in off.
function off_Callback(hObject, eventdata, handles)
% hObject    handle to off (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
%fwrite(s,1);
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
    ylim([-5 inf])
    %save('filed','A.')
end


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
sig_tmp= downsample(sig,1);
sig_tmp=round ((sig_tmp+1)*200);
sig_tmp1=sig_tmp(1:end);


% --- Executes on button press in ADC.
function ADC_Callback(hObject, eventdata, handles)
% hObject    handle to ADC (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
global s
%fwrite(s,1);
% y = 0;
% while(y<1)
%     %x = x + 1;
%     A = fread(s, 1500, 'uint8');
%     B = A;
%     display(A);
%     drawnow;
%     plot(A,'r-')
%     grid on;
%     hold off;
%     %save('Datos','B');
%     %t(ii) - toc;
%     pause(0.1);
%     y = y + 1;
%     ylim([-5 20])
%     %save('filed','A.')
% end


% --- Executes on button press in on.
function on_Callback(hObject, eventdata, handles)
% hObject    handle to on (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,1);


% --- Executes on button press in Apaga.
function Apaga_Callback(hObject, eventdata, handles)
% hObject    handle to Apaga (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global s
fwrite(s,0);
