using Microsoft.AspNetCore.Mvc;
using YourNamespace.Services;

namespace YourNamespace.Controllers
{
    public class HomeController : Controller
    {
        private readonly IMessageService _messageService;

        public HomeController(IMessageService messageService) 
            => _messageService = messageService;

        // Index action - Home page
        public IActionResult Index()
        {
            ViewData["Message"] = _messageService.GetMessage();
            return View();
        }

        // Privacy action
        public IActionResult Privacy() => View();
    }
}
