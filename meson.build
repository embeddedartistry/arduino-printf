project('Arduino-Printf', 'cpp',
  version : '1.1.0',
  license : 'MIT',
  default_options : ['buildtype=minsize',
                     'b_lto=true',
                     'c_std=gnu11',
                     'cpp_std=gnu++11',
                     'b_staticpic=false',
                     ],
  )

assert(meson.is_cross_build(), 'This library can only be built in a cross build environment.')

if host_machine.cpu_family() != 'avr'
	error('The Meson build for this library is only configured for AVR processors')
endif

arduinocore = subproject('arduinocore-avr')
arduinocore_dep = arduinocore.get_variable('arduinocore_dep')
arduinocore_main_dep = arduinocore.get_variable('arduinocore_main_dep')

libPrintf_includes = include_directories('src')

libPrintf = static_library('Printf',
	'src/LibPrintf.cpp',
	include_directories: libPrintf_includes,
	dependencies: arduinocore_dep,
)

libPrintf_dep = declare_dependency(
	include_directories: libPrintf_includes,
	link_with: libPrintf,
)

if meson.is_subproject() == false
	# Compile example applications
	executable('default_to_serial',
		files('extras/sketch_cpp/default_to_serial.cpp'),
		dependencies: [
			libPrintf_dep,
			arduinocore_dep,
			arduinocore_main_dep,
		],
		install: false
	)

	executable('override_putchar',
		files('extras/sketch_cpp/override_putchar.cpp'),
		dependencies: [
			libPrintf_dep,
			arduinocore_dep,
			arduinocore_main_dep,
		],
		install: false
	)

	if host_machine.cpu() == 'atmega2560'
		# Serial1 is only usable on the Mega, not the Uno
		executable('specify_print_class',
			files('extras/sketch_cpp/specify_print_class.cpp'),
			dependencies: [
				libPrintf_dep,
				arduinocore_dep,
				arduinocore_main_dep,
			],
			install: false
		)
	endif
endif
