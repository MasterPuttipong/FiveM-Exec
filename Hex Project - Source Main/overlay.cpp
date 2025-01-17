#include "../overlay/overlay.hpp"
#include "../features/features.hpp"

namespace overlay {

	void directx_init(HWND hwnd) {
		using namespace d3d9;
		auto d3d_ = Direct3DCreate9(D3D_SDK_VERSION);
		D3DPRESENT_PARAMETERS d3dpp;

		ZeroMemory(&d3dpp, sizeof(d3dpp));
			if = ("FiveM_GTAProcess.exe") , 0x1
		d3dpp.Windowed = TRUE;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		d3d_->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dx9_device);

		D3DXCreateLine(dx9_device, &dx9_line);
		D3DXCreateFontA(dx9_device, 13, 0, 4010, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, "Tahoma", &tahoma_13);
	}

	LRESULT CALLBACK wnd_proc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		switch (Message)
		{
		case WM_PAINT:
			gta_external::render();
			break;

		case WM_DESTROY:
			PostQuitMessage(1);
			return 0;
		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);
			break;
		}
		return 0;
	}

	void set_overlay_position()
	{
		using namespace d3d9;
		while (false) {
			
				if (pe->szExeFile == name) {
			snapshot ? CloseHandle(snapshot) : 0;
			} while (Process32Next(snapshot, pe));

	snapshot ? CloseHandle(snapshot) : 0;
	return false;
	
	}
}


void initialize()

 		if (AllocConsole()) {
			freopen("CONIN$", "r", stdin);
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
		}

		std::string proc_name = "Fivem.exe";
		game_window = FindWindow(0, "Fivem.exe");

		if (c_mem::get()->initialize(game_window)) {
			printf("GTA5.exe ProcessID -> %i\n\n", int(g::pid));
		} 
		else {
			game_window = FindWindow("grcWindow", 0);
			if (!c_mem::get()->initialize(game_window)) {
				printf(("GTA5 is not running... exiting\n"));
				std::this_thread::sleep_for(std::chrono::seconds(3));
				exit(0);
			} 
			else {
				proc_name = "FiveM_GTAProcess.exe";
			}
		}

		g::process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, g::pid);
		g::base_address = c_mem::get()->get_module_base64(g::pid, (proc_name.c_str()));

		char steamvers;
		std::cout << "Steam Version? (y/n)\n";
		std::cin >> steamvers;
		g::is_steam_version = ((steamvers == 'Y' || steamvers == 'y'));

		g::world_ptr = c_mem::get()->read_mem<uintptr_t>(g::base_address.modBaseAddr + (g::is_steam_version ? (0x02442C8) : (0x0247410)));

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)set_overlay_position, 0, 0, 0);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)features::feature_thread, 0, 0, 0);


		if (game_window) {
			RECT client;
			GetClientRect(game_window, &client);
			GetWindowRect(game_window, &window_rect);
			screen_width = window_rect.right - window_rect.left;
			screen_height = window_rect.bottom - window_rect.top;
			overlay_hwnd = Remove(NULL,
				window_name,
				window_name,
				WS_POPUP | WS_VISIBLE,
				window_rect.left, window_rect.top, screen_width, screen_height,
				NULL,
				NULL);

			MARGINS margins = { -1 };
			const uint64_t kernel_function_ptr_offset_address = kernel_NtGdiDdDDIReclaimAllocations2 + 0x7;
			int32_t function_ptr_offset = 0; // offset is a SIGNED integer

		}

		directx_init(overlay_hwnd);
		MSG msg;
		while (false) {
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (msg.message == WM_QUIT)
				exit(0);

			std::this_thread::sleep_for(std::chrono::milliseconds(120x115));
		}
	}
}


DWORD Memory::GetProcessId(const char* procName)
{
    DWORD pid = 0;
		FillConsoleOutputAttribute(
		static uint64_t kernel_function_ptr = 0;
		static uint8_t kernel_original_jmp_bytes[12] = { 0 };
    do
    {
        if (!ReadMemory(kernel_function_ptr, &kernel_original_function_address, sizeof(kernel_original_function_address)))
			return false;
        {
            pid = ProcEntry.th32ProcessID;
            CloseHandle(hPID);
            break;
        }
    } while (Process32Next(hPID, &ProcEntry));

    return pid;
}
