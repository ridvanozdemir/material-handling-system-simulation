function varargout = gui_ver_301(varargin)
% GUI_VER_301 MATLAB code for gui_ver_301.fig
%      GUI_VER_301, by itself, creates a new GUI_VER_301 or raises the existing
%      singleton*.
%
%      H = GUI_VER_301 returns the handle to a new GUI_VER_301 or the handle to
%      the existing singleton*.
%
%      GUI_VER_301('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_VER_301.M with the given input arguments.
%
%      GUI_VER_301('Property','Value',...) creates a new GUI_VER_301 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_ver_301_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_ver_301_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui_ver_301

% Last Modified by GUIDE v2.5 06-Aug-2016 13:21:25

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_ver_301_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_ver_301_OutputFcn, ...
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


% --- Executes just before gui_ver_301 is made visible.
function gui_ver_301_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui_ver_301 (see VARARGIN)

% Choose default command line output for gui_ver_301
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);




% --- Outputs from this function are returned to the command line.
function varargout = gui_ver_301_OutputFcn(hObject, ~, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in pushbutton_start.
function pushbutton_start_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ver_601','SimulationCommand','start')
hat_uz = str2double(get(handles.edit_hat_uz,'String'));
ort_hiz = str2double(get(handles.edit_ort_hiz,'String'));
bolge_say = str2double(get(handles.edit_bolge_say,'String'));
as_sure = get(handles.edit_as_sure,'String');
bolge_sure=num2str((hat_uz/bolge_say)/ort_hiz);
set(handles.text_bolge_sure,'String', bolge_sure);
set_param('ver_601/bolge_sure','Value', bolge_sure);
set_param('ver_601/as_sure','Value', as_sure);

value_1 = get(handles.edit_asan1,'String');
set_param('ver_601/asan1','Value',value_1);
value_2 = get(handles.edit_asan2,'String');
set_param('ver_601/asan2','Value',value_2);
value_3 = get(handles.edit_asan3,'String');
set_param('ver_601/asan3','Value',value_3);
value_4 = get(handles.edit_asan4,'String');
set_param('ver_601/asan4','Value',value_4);
value_5 = get(handles.edit_yuk,'String');
set_param('ver_601/yuk','Value',value_5);

function edit_asan1_Callback(hObject, eventdata, handles)
value_1 = get(hObject,'String');
set_param('ver_601/asan1','Value',value_1);


% --- Executes during object creation, after setting all properties.
function edit_asan1_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in checkbox_switch.
function checkbox_switch_Callback(hObject, eventdata, handles)

value = get(hObject,'Value');

if value == 0
    set_param('ver_601/Manual Switch','sw','0');
else
    set_param('ver_601/Manual Switch','sw','1');
end

% Assign handles and the switch object to the base workspace
%assignin('base','gui_ver_301_handles',handles)
%assignin('base','switch_hObject',handles.checkbox_switch)



function edit_time_Callback(hObject, eventdata, handles)
% hObject    handle to edit_time (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_time as text
%        str2double(get(hObject,'String')) returns contents of edit_time as a double
 


% --- Executes during object creation, after setting all properties.
function edit_time_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_time (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function edit_asan2_Callback(hObject, eventdata, handles)
value_2 = get(hObject,'String');
set_param('ver_601/asan2','Value',value_2);

function edit_asan2_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_asan3_Callback(hObject, eventdata, handles)
value_3 = get(hObject,'String');
set_param('ver_601/asan3','Value',value_3);

function edit_asan3_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_asan4_Callback(hObject, eventdata, handles)
value_4 = get(hObject,'String');
set_param('ver_601/asan4','Value',value_4);
function edit_asan4_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_stop.
function pushbutton_stop_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ver_601','SimulationCommand','stop')


% --- Executes on button press in pushbutton_pause.
function pushbutton_pause_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_pause (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ver_601','SimulationCommand','pause')


% --- Executes on button press in pushbutton_cont.
function pushbutton_cont_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_cont (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('ver_601','SimulationCommand','continue')



function edit_as1_Callback(hObject, eventdata, handles)
% hObject    handle to edit_as1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_as1 as text
%        str2double(get(hObject,'String')) returns contents of edit_as1 as a double


% --- Executes during object creation, after setting all properties.
function edit_as1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_as1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_as2_Callback(hObject, eventdata, handles)
% hObject    handle to edit_as2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_as2 as text
%        str2double(get(hObject,'String')) returns contents of edit_as2 as a double


% --- Executes during object creation, after setting all properties.
function edit_as2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_as2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_as4_Callback(hObject, eventdata, handles)
% hObject    handle to edit_as4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_as4 as text
%        str2double(get(hObject,'String')) returns contents of edit_as4 as a double


% --- Executes during object creation, after setting all properties.
function edit_as4_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_as4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_as3_Callback(hObject, eventdata, handles)
% hObject    handle to edit_as3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_as3 as text
%        str2double(get(hObject,'String')) returns contents of edit_as3 as a double


% --- Executes during object creation, after setting all properties.
function edit_as3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_as3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_hat_uz_Callback(hObject, eventdata, handles)
% hObject    handle to edit_hat_uz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_hat_uz as text
%        str2double(get(hObject,'String')) returns contents of edit_hat_uz as a double



% --- Executes during object creation, after setting all properties.
function edit_hat_uz_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_hat_uz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_ort_hiz_Callback(hObject, eventdata, handles)
% hObject    handle to edit_ort_hiz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_ort_hiz as text
%        str2double(get(hObject,'String')) returns contents of edit_ort_hiz as a double


% --- Executes during object creation, after setting all properties.
function edit_ort_hiz_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_ort_hiz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_bolge_say_Callback(hObject, eventdata, handles)
% hObject    handle to edit_bolge_say (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_bolge_say as text
%        str2double(get(hObject,'String')) returns contents of edit_bolge_say as a double


% --- Executes during object creation, after setting all properties.
function edit_bolge_say_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_bolge_say (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_as_sure_Callback(hObject, eventdata, handles)
% hObject    handle to edit_as_sure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_as_sure as text
%        str2double(get(hObject,'String')) returns contents of edit_as_sure as a double


% --- Executes during object creation, after setting all properties.
function edit_as_sure_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_as_sure (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton_ciz.
function pushbutton_ciz_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton_ciz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
load('as1.mat')
load('as2.mat')
load('as3.mat')
load('as4.mat') 

 figure
 %axes(handles.axes1)
 plot(as1(1,:),as1(2,:),'-b',as2(1,:),as2(2,:),'-.g',as3(1,:),as3(2,:),'r',as4(1,:),as4(2,:),'m');
 legend('asansör1','asansör2','asansör3','asansör4','Location','northwest');
 xlabel('Zaman');
 ylabel('Kasa sayýsý');
 title('Zamana Bagli Kasa Dagitimi');
  



function edit_stop_Callback(hObject, eventdata, handles)
% hObject    handle to edit_stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_stop as text
%        str2double(get(hObject,'String')) returns contents of edit_stop as a double
stoptime = get(hObject,'String');
set_param('ver_601/son','Value',stoptime);

% --- Executes during object creation, after setting all properties.
function edit_stop_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_stop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

%set_param('ver_601','SimulationCommand','stop')



function edit_yuk_Callback(hObject, eventdata, handles)
% hObject    handle to edit_yuk (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_yuk as text
%        str2double(get(hObject,'String')) returns contents of edit_yuk as a double
value_5 = get(hObject,'String');
set_param('ver_601/yuk','Value',value_5);


% --- Executes during object creation, after setting all properties.
function edit_yuk_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_yuk (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
