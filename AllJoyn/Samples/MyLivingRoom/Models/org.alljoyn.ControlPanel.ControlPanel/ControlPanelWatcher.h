//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace org { namespace alljoyn { namespace ControlPanel { namespace ControlPanel {

ref class ControlPanelWatcher;

public interface class IControlPanelWatcher
{
    event Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynServiceInfo^>^ Added;
    event Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>^ Stopped;
};

public ref class ControlPanelWatcher sealed : [Windows::Foundation::Metadata::Default] IControlPanelWatcher
{
public:
    ControlPanelWatcher(Windows::Devices::AllJoyn::AllJoynBusAttachment^ busAttachment);
    virtual ~ControlPanelWatcher();

    // This event will fire whenever a producer for this service is found.
    virtual event Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynServiceInfo^>^ Added 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynServiceInfo^>^ handler) 
        { 
            return _Added += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<ControlPanelWatcher^>(sender), safe_cast<Windows::Devices::AllJoyn::AllJoynServiceInfo^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _Added -= token; 
        } 
    internal: 
        void raise(ControlPanelWatcher^ sender, Windows::Devices::AllJoyn::AllJoynServiceInfo^ args) 
        { 
            _Added(sender, args);
        } 
    }

    // This event will fire whenever the watcher is stopped.
    virtual event Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>^ Stopped 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<ControlPanelWatcher^, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>^ handler) 
        { 
            return _Stopped += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<ControlPanelWatcher^>(sender), safe_cast<Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _Stopped -= token; 
        } 
    internal: 
        void raise(ControlPanelWatcher^ sender, Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs^ args) 
        { 
            _Stopped(sender, args);
        } 
    }

    // Start watching for producers advertising this service.
    void Start();

    // Stop watching for producers for this service.
    void Stop();

internal:
    void OnAnnounce(
        _In_ PCSTR name,
        _In_ uint16_t version,
        _In_ alljoyn_sessionport port,
        _In_ alljoyn_msgarg objectDescriptionArg,
        _In_ const alljoyn_msgarg aboutDataArg);

    void OnPropertyChanged(_In_ PCSTR prop_name, _In_ alljoyn_msgarg prop_value)
    {
        UNREFERENCED_PARAMETER(prop_name); UNREFERENCED_PARAMETER(prop_value);
    }

    property Windows::Devices::AllJoyn::AllJoynBusAttachment^ BusAttachment
    {
        Windows::Devices::AllJoyn::AllJoynBusAttachment^ get() { return m_busAttachment; }
    }

    // Stop watching for producers advertising this service and pass status to anyone listening for the Stopped event.
    void StopInternal(int32 status);

    void BusAttachmentStateChanged(_In_ Windows::Devices::AllJoyn::AllJoynBusAttachment^ sender, _In_ Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs^ args);

private:
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _Added;
    virtual event Windows::Foundation::EventHandler<Platform::Object^>^ _Stopped;

    void UnregisterFromBus();

    Windows::Devices::AllJoyn::AllJoynBusAttachment^ m_busAttachment;
    Windows::Foundation::EventRegistrationToken m_busAttachmentStateChangedToken;

    alljoyn_aboutlistener m_aboutListener;
    
    // Used to pass a pointer to this class to callbacks.
    Platform::WeakReference* m_weak;
};

} } } } 