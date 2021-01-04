function varargout = up_gui_ver_301(varargin)

%create a run time object that can return the value of the gain block's
%output and then put the value in a string.
rto = get_param('ver_601/Clock','RuntimeObject');
str = num2str(rto.OutputPort(1).Data);

%get a handle to the GUI's 'current state' window
distxt = findobj('Tag','edit_time');
%update the gui
set(distxt,'string',str);

end
