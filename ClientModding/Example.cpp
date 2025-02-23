#include "Example.h"
#include "Api/DelphiClasses/TLBSWidgetHandler.h"

Example::Example(const ClientModdingConfig& Config) noexcept
	: ClientModding(Config)
{
	// If you want to do something before ClientModding::Initialize runs.
	// However, you must use beforeRun in priority - this should only be
	// used when your instruction would not work in beforeRun.
	// The reason is that nearly nothing when this function is called,
	// while beforeRun is called *after* everything is initialized.
	// Exception for packet handling, you can already subscribe here.
}

bool Example::beforeRun() noexcept
{
	auto _ = Logger::PushPopModuleName("Example");
	// This method is called after calling Example::Run().
	// You can expect every widgets and modules provided by this API to work
	// once this is called, everything is ready.
	// You should add here, everything that must be initialized, done once.
	// Example: if you want to create a widget, you should create it here.

	bool res = ratufuWidget.Initialize(TLBSWidgetHandler::getNtInstance()->getGameRootWidget(), [this]
		{
			packetMng.Receive("info test");
		});
	if (!res)
		return false;

	Logger::Success("Successfully initialized");
	return true;
}

void Example::onShowNostaleSplash() noexcept
{
	// This method is called by the game itself, before initializing the game.
}

void Example::onFreeNostaleSplash() noexcept
{
	// This method is called by the game itself, once initializing the game is done.
}

void Example::tick() noexcept
{
	// This method is called every tick once you call Example::Run() and after
	// beforeRun returns true.
	// You should add here, everything that must be done periodically.
	// Example: refreshing the clock if you have one, etc.
}
