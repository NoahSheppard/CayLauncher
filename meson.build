project('CayLauncher', 'c')
gtk_dep = dependency('gtk4')

windows = import('windows')
windows_args = []
if host_machine.system() == 'windows'
    windows_args = ['-mwindows']
endif

executable('CayLauncher', 'main.c', 
    dependencies: [gtk_dep],
    c_args: windows_args,
    win_subsystem: 'windows')