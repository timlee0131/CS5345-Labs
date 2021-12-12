import React from 'react'
import Button from 'react-bootstrap/Button'

function Overview() {
    return (
        <div class="jumbotron">
            <h1 class="display-4">Welcome to Sorting Engine</h1>
            <p class="lead">
                This is a product website that showcases both the web and native versions of the sorting engine. 
            </p>
            <hr class="my-4" />
            <p>
                Both the web and native versions of this application were built with C++ on the backend and transpiled using Emscripten and Web Assembly. The sorting functions (bubble, merge, and insertion) were written entirely in C++ using multithreading as well as using libraries like std::vector and later converted to a javascript library using Emscripten. These transpiled libraries were then utilized on the web version of this application in conjunction with HTML and javascript. The native version of this application was built using Electron, a cross-platform framework developed by Github that allows for easy development of desktop apps using web technologies. In this product website, you will be able to demo both the web and native versions of this application.
            </p>
            <p class="lead">
                <a href="CS5345Final/Emscripten/frontend/sort.html" target="_blank"><Button size='lg' variant="dark">Demo Web App</Button></a>{' '}
                <a href="code.zip" download><Button size='lg' variant="dark">Download Native App</Button></a>
            </p>
        </div>
    )
}

export default Overview