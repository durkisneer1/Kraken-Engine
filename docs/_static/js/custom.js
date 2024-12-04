document.addEventListener("DOMContentLoaded", () => {
    const menuHeaders = document.querySelectorAll('.wy-menu-vertical .caption');
    let hasCurrent = false;

    menuHeaders.forEach(header => {
        const connectedMenu = header.nextElementSibling; // The dropdown menu (e.g., `ul`)

        // Toggle dropdown visibility on click
        header.addEventListener('click', () => {
            const isActive = connectedMenu.classList.contains('active');

            // Close all dropdowns
            menuHeaders.forEach(otherHeader => {
                const otherMenu = otherHeader.nextElementSibling;
                otherMenu.classList.remove('active');
                otherHeader.classList.remove('active');
            });

            // Open the clicked dropdown if it was closed
            if (!isActive) {
                connectedMenu.classList.add('active');
                header.classList.add('active');
            }
        });

        // Automatically expand the dropdown if it contains the "current" page
        if (connectedMenu.querySelector('.current')) {
            connectedMenu.classList.add('active');
            header.classList.add('active');
            hasCurrent = true;
        }
    });

    // If no dropdown contains the "current" page, expand the first section by default
    if (!hasCurrent && menuHeaders.length > 0) {
        menuHeaders[0].classList.add('active');
        menuHeaders[0].nextElementSibling.classList.add('active');
    }
});
