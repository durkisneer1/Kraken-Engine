Creating a Window
=================

After following the :doc:`installation` guide, you are ready for your first Kraken Engine program.
The following code creates a window and keeps it open until the user closes it.

.. raw:: html

    <div class="highlight"><pre>
    <span class="cp">#include</span> <span class="cpf">&lt;KrakenEngine.hpp&gt;</span>

    <span class="kt">int</span> <span class="nf">main</span>() {
        <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">init</span>({<span class="mi">800</span>, <span class="mi">600</span>});
        <span class="nc">kn</span>::<span class="nc">Event</span> event;

        <span class="k">while</span> (<span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">isOpen</span>()) {
            <span class="k">while</span> (<span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">pollEvent</span>(event)) {
                <span class="c1">// handle events</span>
            }
            <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">flip</span>();
        }
        <span class="nc">kn</span>::<span class="nc">window</span>::<span class="nf">quit</span>();

        <span class="k">return</span> <span class="n">EXIT_SUCCESS</span>;
    }
    </pre></div>

Explanation
-----------

This simple program serves as a basic skeleton for applications built with the Kraken Engine.
Let's break down the key components that make this program function:

* Initializing the Window
    ``kn::window::init({800, 600})`` sets up a rendering window with a resolution of 800x600 pixels.
    This function prepares the underlying graphical context, ensuring the application is ready to display content.

* Event Handling
    Before entering the main game loop, an ``Event`` union is instantiated.
    This union acts as a container for user inputs and system events.
    The call to ``kn::window::pollEvent(event)`` continuously monitors for user interactions or system-generated signals, populating the event union with the details of the most recent occurrence.

* Closing the Application
    By default, Kraken Engine applications close when the user clicks the window’s close button.
    Upon detecting this event internally, the call to ``kn::window::close()`` ends the game loop.

* Updating the Display
    ``kn::window::flip()`` acts as the final piece in the game loop, swapping the back buffer to the front.
    This step ensures that any rendering operations performed during the loop are visually updated on the screen.
    Think of it as flipping the pages of a book—ensuring smooth, sequential updates for the user.

This template establishes a foundation for more advanced game logic and rendering.
In-depth tutorials in the next section cover the more intricate aspects of the Kraken Engine.
