using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using YourNamespace.Services;

var builder = WebApplication.CreateBuilder(args);

// Register services for Dependency Injection
builder.Services.AddScoped<IMessageService, MessageService>(); 

// Add MVC support
builder.Services.AddControllersWithViews();

var app = builder.Build();

// Configure middleware
app.UseRouting();

// Default route: HomeController -> Index action
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}"
);

app.Run();
